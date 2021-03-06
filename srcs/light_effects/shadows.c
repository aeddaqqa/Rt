/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/06 12:46:55 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"
int				cmp_vect(t_vect3 lhs, t_vect3 rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)	
		return (1);
	return (0);
}

// int				cmp_obj(t_object *lhs, t_object *rhs)
// {
// 	if ((lhs->type == rhs->type) && 
// 	(cmp_vect(lhs->position, rhs->position)) && 
// 	(cmp_vect(lhs->translation ,rhs->translation)) &&
// 	(cmp_vect(lhs->rotation, rhs->rotation)) &&
// 	(cmp_vect(lhs->color, rhs->color)) &&
// 	(cmp_vect(lhs->point_a, rhs->point_a) )&&
// 	(cmp_vect(lhs->point_b, rhs->point_b ))&&
// 	(cmp_vect(lhs->point_c, rhs->point_c))&&
// 	(cmp_vect(lhs->point_d, rhs->point_d))&&
// 	(cmp_vect(lhs->corner[0], rhs->corner[0]))&&
// 	(cmp_vect(lhs->corner[1], rhs->corner[1]))&&
// 	(cmp_vect(lhs->orientation, rhs->orientation ))&&
// 	(cmp_vect(lhs->normal, rhs->normal)) &&
// 	(lhs->height == rhs->height )&&
// 	(lhs->radius == rhs->radius) &&
// 	(lhs->radius1 == rhs->radius1) &&
// 	(lhs->radius2 == rhs->radius2 )&&
// 	(lhs->distance == rhs->distance) &&
// 	(lhs->angle == rhs->angle )&&
// 	(lhs->is_ref == rhs->is_ref) &&
// 	(lhs->is_transp == rhs->is_transp))
// 	return (1);
// 	return (0);
// }

int				in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	t_object	o;
	double		t;
	double		distance;
	t_ray		shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		copy_obj(&o, obj);
		if (object->id != obj->id\
				&& (t = rt->intersection[obj->type](&o, &shadow)) > 0.0)
		{
			shadow.hit_point = v_c_prod(shadow.direction, t);
			distance = sqrtf(dot(shadow.hit_point, shadow.hit_point));
			if (distance < light->d && !obj->is_transp)
				return (0);
			else if (obj->is_transp)
				light->intensity *= obj->is_transp;
		}
		obj = obj->next;
	}
	return (1);
}
