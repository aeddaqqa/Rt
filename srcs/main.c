/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/10 18:56:12 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_mlx *init_mlx(t_rt *rt)
{
	t_mlx *new;

	if (!(new = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		free_rt(&rt);
		return (NULL);
	}
	new->ptr = mlx_init();
	new->win = mlx_new_window(new->ptr, W, H, "RT");
	new->img = mlx_new_image(new->ptr, W, H);
	new->data = (int *)mlx_get_data_addr(new->img, &new->bpp,
										 &new->ls, &new->end);
	return (new);
}

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

void draw(t_rt *rt)
{
	t_ray *ray;
	t_hit hit;
	int y;
	int x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ray = ray_init(rt, x, y);
			hit.t = INFINITY;
			if (raycast(rt->objects, *ray, &hit))
			{
				if (x == W / 2 && y == H / 2)
				{
					printf("test\n");
				}
				rt->mlx->data[y * W + x] = ft_shade_object(&hit, rt->lights, rt->objects, ray);
			}
			x++;
		}
		y++;
	}
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
		if (!(rt->mlx = init_mlx(rt)))
			destroy(SYNTAX_ERROR);
		cam_cord_system(rt->cameras);
		draw(rt);
		mlx_put_image_to_window(rt->mlx->ptr, rt->mlx->win, rt->mlx->img, 0, 0);
		mlx_loop(rt->mlx->ptr);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
