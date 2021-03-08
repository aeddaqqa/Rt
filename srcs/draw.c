/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:53:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 11:42:16 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			copy_obj_help(t_object *n_obj, t_object *obj)
{
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
	n_obj->texture = obj->texture;
}

void			copy_obj(t_object *n_obj, t_object *obj)
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
	copy_obj_help(n_obj, obj);
}

unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			x_t[2];
	t_object		close_tmp[2];
	t_object		*tmp;
	t_color			color;
	t_color			color1;

	tmp = rt->objects;
	ray->t = -1.0;
	x_t[1] = -1.0;
	color = (t_color){0, 0, 0};
	while (tmp)
	{
		copy_obj(&close_tmp[1], tmp);
		x_t[0] = rt->intersection[close_tmp[1].type](&close_tmp[1], ray);
		if (x_t[0] != -1 && (x_t[0] < x_t[1] || x_t[1] == -1.0))
		{
			copy_obj(&close_tmp[0], &close_tmp[1]);
			x_t[1] = x_t[0];
		}
		tmp = tmp->next;
	}
	if (x_t[1] != -1)
		to_rgb(&color, light(&close_tmp[0], ray, rt, x_t[1]));
	rt->lights->type = DIRECT; //to rm
	color1 = is_direct_light(rt, *ray, x_t[1]);
	return (rgb(add_color(color1, color)));
}

void			apply_antiliasing(t_rt *rt, int x, int y)
{
	int		z;
	t_color	c;
	t_ray	*ray;
	t_rr	r;

	z = 0;
	c = (t_color){0, 0, 0};
	while (z < 5)
	{
		r.r1 = (rand() % 10) / 10.;
		r.r2 = (rand() % 10) / 10.;
		ray = ray_init(rt, x, y, r);
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

void			draw_scene(t_rt *rt, int x, int y)
{
	t_rr	r;
	t_ray	*ray;

	r.r1 = .5;
	r.r2 = .5;
	ray = ray_init(rt, x, y, r);
	rt->sdl->data[y * W + x] = pixel_color(rt, ray);
	free(ray);
}
