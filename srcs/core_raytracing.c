/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:21:03 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/04 15:54:42 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		*init_tab(void)
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(4 * 6);/*free*/
	while (i < 6)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void		initab(int *tab)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		tab[i] = 0;
		i++;
	}
}

void	copy_obj(t_object *n_obj, t_object *obj)
{
	n_obj->type = obj->type;
	n_obj->position = obj->position;
	n_obj->translation = obj->translation;
	n_obj->rotation = obj->rotation;
	n_obj->color = obj->color;
	n_obj->point_a = obj->point_a;
	n_obj->point_b = obj->point_b;
	n_obj->point_c = obj->point_c;
	n_obj->point_d = obj->point_d;
	n_obj->corner[0] = obj->corner[0];
	n_obj->corner[1] = obj->corner[1];
	n_obj->orientation = obj->orientation;
	n_obj->normal = obj->normal;
	n_obj->height = obj->height;
	n_obj->radius = obj->radius;
	n_obj->radius1 = obj->radius1;
	n_obj->radius2 = obj->radius2;
	n_obj->distance = obj->distance;
	n_obj->angle = obj->angle;
	n_obj->is_ref = obj->is_ref;
	n_obj->is_transp = obj->is_transp;
	n_obj->refraction_index = obj->refraction_index;
	n_obj->cyl = obj->cyl;
	n_obj->sph = obj->sph;
	n_obj->cne = obj->cne;
	n_obj->id = obj->id;
}

unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			x;
	double			t;
	unsigned int	color;
	t_object		close_object;
	t_object		*tmp;
	t_object		tmp2;

	tmp = rt->objects;
	ray->t = -1.0;
	t = -1.0;
	color = 0;
	while (tmp)
	{
		copy_obj(&tmp2, tmp);
		x = rt->intersection[tmp2.type](&tmp2, ray);
		if (x != -1 && (x < t || t == -1.0))
		{
			copy_obj(&close_object, &tmp2);
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
		return (light(&close_object, ray, rt, t));
	return (0);
}

t_color int_to_rgb(int m)
{
	t_color rgb;

	rgb.x = (m >> 16) & 255;
	rgb.y = (m >> 8) & 255;
	rgb.z = (m & 255);
	return (rgb);
}

void		apply_antiliasing(t_rt *rt, int x, int y)
{
	int		z;
	t_color	c;
	double r1;
	double r2;
	t_ray *ray;

	z = 0;
	c = (t_color){0, 0, 0};
	while (z < 5)
	{
			r1 = (rand() % 10) / 10.;
			r2 = (rand() % 10) / 10.;
			ray = ray_init(rt, x, y, r1, r2);
			rt->sdl->data[y * W + x] = pixel_color(rt, ray);
			c = vect_add(c, int_to_rgb(pixel_color(rt, ray)));
			free(ray);
			z++;
	}
	c = v_c_prod(c, (double)(1.0 / 5.0));
	c.x = (int)c.x & 255;
	c.y = (int)c.y & 255;
	c.z = (int)c.z & 255;
	rt->sdl->data[y * W + x] = rgb_to_int(c);
}

void		draw_scene(t_rt *rt, int x, int y)
{
	// t_color	c;
	t_ray *ray;

	ray = ray_init(rt, x, y, .5, .5);
	rt->sdl->data[y * W + x] = pixel_color(rt, ray);
	free(ray);
}

void draw_first_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}
void draw_second_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 400;
	while (y < 800)
	{
		x = 0;
		while (x < 400)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}

void draw_third_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 0;
	while (y < 400)
	{
		x = 400;
		while (x < 800)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}

void draw_fourth_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 400;
	while (y < 800)
	{
		x = 400;
		while (x < 800)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}

void draw(void *r)
{
	int		y;
	int		x;
	t_rt	*rt;

	rt = (t_rt*)r;
	srand(time(0));
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}

void		first_render(t_rt *rt)
{
	SDL_Thread  *tab[4];
	int			threadReturnValue[4];

	tab[0] = SDL_CreateThread((SDL_ThreadFunction)draw_first_thread, "draw_first_thread", (void *)rt);
	tab[1] = SDL_CreateThread((SDL_ThreadFunction)draw_second_thread, "draw_second_thread", (void *)rt);
	tab[2] = SDL_CreateThread((SDL_ThreadFunction)draw_third_thread, "draw_third_thread", (void *)rt);
	tab[3] = SDL_CreateThread((SDL_ThreadFunction)draw_fourth_thread, "draw_fourth_thread", (void *)rt);
	SDL_WaitThread(tab[0], &threadReturnValue[0]);
	SDL_WaitThread(tab[1], &threadReturnValue[1]);
	SDL_WaitThread(tab[2], &threadReturnValue[2]);
	SDL_WaitThread(tab[3], &threadReturnValue[3]);
	// draw(rt);
	render(rt->sdl, rt);
	// exit(0);
	menu(rt->sdl, rt->save_filter);
	rt->sdl->loop = 1;
}

int		core(t_rt **r)
{	
	int		to_do;
	t_rt	*rt;

	rt = *r;
	if ((rt->sdl->event.type == SDL_WINDOWEVENT &&\
	rt->sdl->event.window.event == SDL_WINDOWEVENT_CLOSE) || rt->sdl->event.type == SDL_QUIT)
		return (0);
	rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
	if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
	{
		if (rt->save)
			image_create(rt->sdl->data);
		rt->sdl->loop = 0;
	}
	if (rt->sdl->key_table[SDL_SCANCODE_O])
	{
		if (rt->cameras->next)
		{
			rt->cameras = rt->cameras->next;
			new_camera(rt);
			first_render(rt);
			render(rt->sdl, rt);
		}
	}
	if (rt->sdl->key_table[SDL_SCANCODE_P])
	{
		if (rt->cameras->prev)
		{
			rt->cameras = rt->cameras->prev;
			new_camera(rt);
			first_render(rt);
			render(rt->sdl, rt);
		}
	}
	else if (SDL_GetMouseFocus() == rt->sdl->win_menu)
	{
		if ((to_do = re_calc(rt->sdl, rt->sdl->event)) != -1)
		{
			if (rt->save_filter == to_do)
				rt->save_filter = -1;/*FIKRA*/
			else
			{
				rt->filters[to_do] = 1;
				rt->save_filter = to_do;
			}
			first_render(rt);
			render(rt->sdl, rt);
		}
		menu(rt->sdl, rt->save_filter);
	}
	return (1);
}

void		rtrace(t_rt *rt)
{
	// int		to_do;

	rt->sdl->loop = 2;
	rt->save_filter = -1;
	rt->filters = init_tab();/*free*/
	while (rt->sdl->loop)
	{
		initab(rt->filters);/*free*/
		if (rt->sdl->loop == 2)
			first_render(rt);
		else if (SDL_PollEvent(&rt->sdl->event))
		// SDL_PollEvent(&rt->sdl->event);
		// rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
		// if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
			// exit(0);
		{
			if (!core(&rt))
				break;
			
		}
		// SDL_RenderClear(rt->sdl->ren_ptr);
		// SDL_UpdateTexture(rt->sdl->tex_ptr, NULL, rt->sdl->tex, 1024 * 4);
		// SDL_RenderCopy(rt->sdl->ren_ptr, rt->sdl->tex_ptr, NULL, NULL);
		// SDL_RenderPresent(rt->sdl->ren_ptr);
	}
	free(rt->filters);
	destroy_sdl(&rt->sdl);
}
