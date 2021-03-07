/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ref_trsp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:29:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 16:43:51 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_vect3	lit_comp(t_rt *rt, t_light light, t_object *object, t_ray *ray)
{
	t_vect3 color;
	float	n_l;

	if (object->texture->type != NONE && (object->type == SPHERE ||\
	object->type == CYLINDER || object->type == CONE ||\
	object->type == PLANE))
		texture(&object, ray->hit_point, rt->hooks);
	light.direction = vect_sub(light.position, ray->hit_point);
	light.direction = normalize(light.direction);
	n_l = dot(light.direction, object->normal);
	color = (t_vect3){0.0f, 0.0f, 0.0f};
	if (n_l > 0)
		color = vect_add(color, diffuse(&light, n_l, object));
	color = add_color(color,\
	fraction(reflex_col(rt, *ray, object, &light), object->is_ref));
	color = add_color(color,\
	fraction(refract_color(rt, *ray, object, &light), object->is_transp));
	return (color);
}

static t_object	*refintrsct(t_rt *rt, t_ray *ray, t_object *node)
{
	double			x;
	t_object		*close;
	t_object		*tmp;
	t_object		o;

	tmp = rt->objects;
	close = NULL;
	ray->t = -1.0;
	x = -1;
	while (tmp)
	{
		copy_obj(&o, tmp);
		if (node->id != o.id)
		{
			x = rt->intersection[o.type](&o, ray);
			if (x > 0 && (x < ray->t || ray->t < 0))
			{
				close = tmp;
				ray->t = x;
			}
		}
		tmp = tmp->next;
	}
	return (close);
}

t_color			ref_trsp(t_rt *rt, t_object *obj, t_ray reflect, t_light *light)
{
	t_object	*close;

	if ((close = refintrsct(rt, &reflect, obj)) && reflect.t != -1)
	{
		reflect.hit_point = vect_add(reflect.origin,\
		v_c_prod(reflect.direction, reflect.t));
		close->normal = rt->normal[close->type](close, &reflect);
		return (lit_comp(rt, *light, close, &reflect));
	}
	return ((t_color){0, 0, 0});
}
