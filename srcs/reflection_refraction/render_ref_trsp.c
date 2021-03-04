/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ref_trsp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:29:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/04 17:30:32 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_vect3	lit_comp(t_rt *rt, t_light light, t_object *object, t_ray *ray)
{
	t_vect3 color;
	float	n_l;

	light.direction = vect_sub(light.position, ray->hit_point);
	light.direction = normalize(light.direction);
	n_l = dot(light.direction, object->normal);
	color = (t_vect3){0.0f, 0.0f, 0.0f};
	if (n_l > 0)
		color = vect_add(color, diffuse(&light, n_l, object));
	color = add_color(color, reflex_col(rt, *ray, object, &light));
	color = add_color(color, refract_color(rt, *ray, object, &light));
	return (color);
}

static t_color	refintrsct(t_rt *rt, t_ray *ray, t_object *node, t_light *light)
{
	double			x;
	double			t;
	unsigned int	color;
	t_object		*close;
	t_object		*tmp;
	t_object		o;

	tmp = rt->objects;
	close = NULL;
	t = -1.0;
	color = 0;
	x = -1;
	while (tmp)
	{
		copy_obj(&o, tmp);
		if (node->id != o.id)
		{
			x = rt->intersection[o.type](&o, ray);
			if (x > 0 && (x < t || t < 0))
			{
				close = tmp;
				t = x;
			}
		}
		tmp = tmp->next;
	}
	if (t != -1 && close)
	{
		ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
		close->normal = rt->normal[close->type](close, ray);
		return (lit_comp(rt, *light, close, ray));
	}
	return ((t_vect3){0, 0, 0});
}

t_color			ref_trsp(t_rt *rt, t_object *obj, t_ray reflect, t_light *light)
{
	return (refintrsct(rt, &reflect, obj, light));
}
