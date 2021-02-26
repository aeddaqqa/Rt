/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ref_trsp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:29:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/25 16:08:52 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color ft_multip_color(t_color c1, t_color c2)
{
	t_color new;
	float tmp;

	tmp = c1.x * c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y * c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.z * c2.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

t_color ft_fraction(t_color c, double fract)
{
	t_color new;
	double tmp;

	tmp = c.x * fract;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.y * fract;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.z * fract;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

int ft_rgb(t_color color)
{
	int new;
	char *ptr;

	ptr = (char *)&new;
	ptr[2] = color.x * 255;
	ptr[1] = color.y * 255;
	ptr[0] = color.z * 255;
	ptr[3] = 0;
	return (new);
}

t_color ft_add_color(t_color c1, t_color c2)
{
	t_color new;
	double tmp;

	tmp = c1.x + c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y + c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c2.z + c1.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

static t_color diffuse(t_light *light, double n_l, t_object *object)
{
	t_color color;

	color = ft_multip_color(ft_fraction(light->color, light->intensity), object->color);
	color = ft_fraction(color, n_l * DIFFUSE);
	return (color);
}

static t_color specular(t_light *l, t_ray *ray, t_object *object)
{
	t_color color;
	t_vect3 h;
	unsigned int alpha;
	double dot_p;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->direction, ray->direction));
	if ((dot_p = dot(object->normal, h)) <= 0)
		return (color);
	dot_p = powf(dot_p, alpha);
	color = ft_fraction(l->color, dot_p * l->intensity * SPECULER); // TODO: specular intensity
	return (color);
}

t_vect3 lit_comp(t_light *light, t_object *object, t_ray *ray)
{
	t_vect3 color;
	float n_l = dot(light->direction, object->normal);

	color = (t_vect3){0.0f, 0.0f, 0.0f};
	light->direction = vect_sub(light->position, ray->hit_point);
	light->direction = normalize(light->direction);

	if (n_l > 0)
		color = vect_add(color, diffuse(light, n_l, object));
	// color = ft_add_color(color, specular(light, ray, hit->object));
	return (color);
}

static t_color ref_intersect(t_rt *rt, t_ray *ray, t_object *node, t_light *light)
{
	double x;
	double t;
	unsigned int color;
	t_object *close_object;
	t_object *tmp;

	tmp = rt->objects;
	close_object = NULL;
	ray->t = -1.0;
	t = -1.0;
	color = 0;
	x = -1;
	while (tmp)
	{
		if (node != tmp)
		{
			x = rt->intersection[tmp->type](tmp, ray);
			if (x != -1 && (x < t || t == -1.0))
			{
				close_object = tmp;
				t = x;
			}
			if (t != -1 && close_object)
			{
				ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
				ray->t = t;
				close_object->normal = rt->normal[close_object->type](close_object, ray);
				return (lit_comp(light, close_object, ray));
			}
		}
		tmp = tmp->next;
	}
	return ((t_vect3){0, 0, 0});
}

t_color ref_trsp(t_rt *rt, t_object *object, t_ray reflect, t_light *light)
{
	return ref_intersect(rt, &reflect, object, light);
}