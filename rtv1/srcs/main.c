/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 06:08:16 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	setup(t_rt *rt, int width, int height)
{
	rt->objects = NULL;
	rt->lights = NULL;
	rt->cam = NULL;
	rt->hit_object = NULL;
	rt->null = (t_vector){0.0, 0.0, 0.0};
	if (!(rt->hit_object = malloc(sizeof(double (*)(t_obj*, t_ray*)) * 4)))
		destroy(rt, MALLOC_ERROR);
	rt->hit_object[0] = hit_plane;
	rt->hit_object[1] = hit_sphere;
	rt->hit_object[2] = hit_cylinder;
	rt->hit_object[3] = hit_cone;
	if (!(rt->m = malloc(sizeof(t_mlx))))
		destroy(rt, MALLOC_ERROR);
	rt->m->ptr = mlx_init();
	rt->m->win = mlx_new_window(rt->m->ptr, width, height, "Rtv1");
	rt->m->img = mlx_new_image(rt->m->ptr, width, height);
	rt->m->data = (int*)mlx_get_data_addr(rt->m->img, &rt->m->a,\
			&rt->m->b, &rt->m->c);
}

void	check_components(t_rt *rt)
{
	if (!rt->cam)
		destroy(rt, CAMERA_ERROR);
	if (!rt->objects)
		destroy(rt, OBJECT_UNDEFINED);
}

int		key_press(int button, t_rt *rt)
{
	if (button == 53)
		destroy(rt, GOODBYE);
	return (1);
}

void	check_args(int ac)
{
	if (ac != 2)
	{
		if (ac > 2)
		{
			ft_putstr("\033[0;31m");
			ft_putendl("TOO MANY ARGUMENTS !!!");
			ft_putstr("\033[0m");
		}
		ft_putstr("\033[0;32m");
		ft_putendl("Usage: ./RTv1 [FILENAME]");
		ft_putstr("\033[0m");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_rt	*rt;
	int		fd;
	int		rd;
	char	buf[1];

	fd = 0;
	check_args(ac);
	if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
		destroy(rt, MALLOC_ERROR);
	setup(rt, W, H);
	if (((fd = open(av[1], O_RDONLY))) <= 0\
			|| (rd = read(fd, buf, 0)) < 0)
		destroy(rt, FILE_ERROR);
	stock(rt, fd);
	check_components(rt);
	draw(rt);
	mlx_hook(rt->m->win, 2, 0, key_press, rt);
	mlx_hook(rt->m->win, 17, 0, &ft_close, rt);
	mlx_loop(rt->m->ptr);
	return (0);
}
