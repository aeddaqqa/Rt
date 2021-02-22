/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/22 15:48:21 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int raycast(t_object *lst, t_ray ray, t_hit *hit)
{
	t_object *p;
	double t;
	t_ray save;

	t = INFINITY;
	hit->object = NULL;
	hit->t = INFINITY;
	p = lst;
	save = obj_intersect(p, hit, ray, t);
	if (hit->object == NULL)
		return (0);
	hit->p = vect_add(save.origin, v_c_prod(save.direction, hit->t));
	ft_compute_normals(hit, &save);
	return (1);
}

t_color raytrace(t_rt *rt, t_hit *hit, t_ray *ray)
{
	t_color	ret;

	ret = (t_color){0, 0, 0};
	if (raycast(rt->objects, *ray, hit))
		ret = ft_shade_object(hit, rt, ray);
	return (ret);
}

void draw(t_rt *rt)
{
	t_ray	*ray;
	t_hit	hit;
	int		y;
	int		x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ray = ray_init(rt, x, y);
			hit.t = INFINITY;
			if (raycast(rt->objects, *ray, &hit))
				rt->sdl->data[y * W + x] = rgb_to_int(raytrace(rt, &hit, ray));
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
		if (rt->sdl)
			rtrace(rt);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}