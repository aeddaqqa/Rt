/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 06:01:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_ray	*ray_init(t_rt *rt, double x, double y)
{
	t_ray		*new;
	double		px;
	double		py;
	t_vector	tmp;
	t_vector	tmp2;

	if (!(new = malloc(sizeof(t_ray))))
		destroy(rt, MALLOC_ERROR);
	new->origin = rt->cam->o;
	px = (2 * ((double)x + 0.5) / W) - 1;
	py = 1 - (2 * ((double)y + 0.5) / H);
	tmp = multip_vec_const(rt->cam->cords.u, px * rt->cam->plan_w);
	tmp2 = multip_vec_const(rt->cam->cords.v, py * rt->cam->plan_h);
	tmp = add_vector(tmp, tmp2);
	tmp = add_vector(tmp, rt->cam->cords.w);
	new->direction = normalize(tmp);
	return (new);
}

unsigned int	obj_normal(t_obj *close_obj, t_ray *ray, t_rt *rt, double t)
{
	ray->hit_point =\
		add_vector(ray->origin, multip_vec_const(ray->direction, t));
	if (close_obj->type == SPHERE)
		close_obj->normal =\
			normalize(sub_vector(ray->hit_point, close_obj->pos));
	else if (close_obj->type == CYLINDER)
		close_obj->normal = cylinder_normal(ray, t, close_obj);
	else if (close_obj->type == PLANE)
		close_obj->normal = plane_normal(ray, close_obj);
	else if (close_obj->type == CONE)
		close_obj->normal = cone_normal(close_obj, t, ray);
	return (light_effect(rt, close_obj, ray));
}

unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			t;
	double			x;
	unsigned int	color;
	t_obj			*close_object;
	t_obj			*tmp;

	tmp = rt->objects;
	close_object = NULL;
	t = -1.0;
	color = 0;
	while (tmp)
	{
		x = rt->hit_object[tmp->type](tmp, ray);
		if (x != -1 && (x < t || t == -1))
		{
			close_object = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
		return (obj_normal(close_object, ray, rt, t));
	return (color);
}

void			draw(t_rt *rt)
{
	int		i;
	int		j;
	t_ray	*ray;

	i = 0;
	ray = NULL;
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			ray = ray_init(rt, i, j);
			rt->m->data[j * W + i] = pixel_color(rt, ray);
			free(ray);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(rt->m->ptr, rt->m->win, rt->m->img, 0, 0);
}
