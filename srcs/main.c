/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/23 19:18:41 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color			ambient(t_object *obj)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, 1.0);/*ambient*/
	color = vect_prod(color, obj->color);
	return (color);
}

t_color	multip_color(t_color c1, t_color c2)
{
	t_color	new;
	float	tmp;

	tmp = c1.x * c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y * c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.z * c2.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

t_color	fraction(t_color c, double fract)
{
	t_color	new;
	double	tmp;

	tmp = c.x * fract;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.y * fract;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.z * fract;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

static t_color			diffuse(t_light *light, double n_l, t_object *object)
{
	t_color		color;

	color =\
		multip_color(fraction(light->color, light->intensity), object->color);
	color = fraction(color, n_l * 1.0);/**/
	return (color);
}

static t_color			specular(t_light *l, t_ray *ray, t_object *object)
{
	t_color			color;
	t_vect3		h;
	unsigned int	alpha;
	double			dott;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->direction, ray->direction));
	if ((dott = dot(object->normal, h)) <= 0)
		return (color);
	dott = powf(dott, alpha);
	color = fraction(l->color, dott * 1.0 * l->intensity);
	return (color);
}

static int				in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	double	t;
	double	distance;
	t_ray	shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		if (obj != object\
				&& (t = rt->intersection[obj->type](obj, &shadow)) > 0.0)
		{
			shadow.hit_point = v_c_prod(shadow.direction, t);
			distance = sqrtf(dot(shadow.hit_point, shadow.hit_point));
			if (distance < light->d)
				return (0);
		}
		obj = obj->next;
	}
	return (1);
}

int		rgb(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x * 255;
	ptr[1] = color.y * 255;
	ptr[0] = color.z * 255;
	ptr[3] = 0;
	return (new);
}

unsigned int			light_effect(t_rt *rt, t_object *object, t_ray *ray)
{
	double			n_l;
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;

	i = 0;
	lights = rt->lights;
	tmp_res[1] = ambient(object);
	while (lights)
	{
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		lights->direction = vect_sub(lights->position, ray->hit_point);
		lights->d = sqrtf(dot(lights->direction, lights->direction));
		lights->direction = normalize(lights->direction);
		n_l = dot(object->normal, lights->direction);
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(lights, n_l, object));
		tmp_res[0] = vect_add(tmp_res[0], specular(lights, ray, object));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, lights, object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = vect_add(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}


int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	ray->hit_point =\
		vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}

unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			t;
	double			x;
	unsigned int	color;
	t_object			*close_object;
	t_object			*tmp;

	tmp = rt->objects;
	close_object = NULL;
	t = -1.0;
	color = 0;
	while (tmp)
	{
		x = rt->intersection[tmp->type](tmp, ray);
		if (x != -1 && (x < t || t == -1))
		{
			close_object = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
		return (light(close_object, ray, rt, t));
	return (0);
}

void draw(t_rt *rt)
{
	t_ray	*ray;
	int		y;
	int		x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ray = ray_init(rt, x, y);
			rt->sdl->data[y * W + x] = pixel_color(rt, ray);
			free(ray);
			x++;
		}
		y++;
	}
}

int		*init_tab()
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

void		rtrace(t_rt *rt)
{
	int		to_do;

	rt->sdl->loop = 2;
	rt->save_filter = -1;
	cam_cord_system(rt->cameras);
	rt->filters = init_tab();
	while (rt->sdl->loop)
	{
		if (rt->sdl->loop == 2)
		{
			draw(rt);
			// TODO: add filters.
			if (rt->filters[2])
				img_noise(rt->sdl->data);
			render(rt->sdl);
			menu(rt->sdl, rt->save_filter);
			rt->sdl->loop = 1;
		}
		else if (SDL_PollEvent(&rt->sdl->event))
		{
			if (rt->sdl->event.type == SDL_WINDOWEVENT &&\
			rt->sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
				break;
			rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
			if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
			{
				if (rt->save)
					image_create(rt->sdl->data);
				rt->sdl->loop = 0;
			}
			else if (SDL_GetMouseFocus() == rt->sdl->win_menu)
			{
				if ((to_do = re_calc(rt->sdl, rt->sdl->event)) != -1)
				{
					rt->filters[to_do] = 1;
					if (rt->save_filter != -1 && rt->save_filter == to_do)
						rt->save_filter = -1;
					else
						rt->save_filter = to_do;
					draw(rt);
					if (rt->filters[2])
						img_noise(rt->sdl->data);
					render(rt->sdl);
				}
				menu(rt->sdl, rt->save_filter);
			}
		}
	}
	free(rt->filters);
	destroy_sdl(&rt->sdl);
}

int main(int ac, char **av)
{
	char *file;
	t_rt *rt;

	file = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		if (!(file = load_file(av[1])))
			exit(0);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!(parse(file, rt)))
		{
			destroy(SYNTAX_ERROR);
			free_rt(&rt);
			free(file);
			exit(0);
		}
		rt->sdl = init_sdl();
		// rt->nbr_lights = 1;
		if (rt->sdl)
			rtrace(rt);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}