/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_ellipsoid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:21:54 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 16:08:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// void		ft_computing_ellipsoid_normal(t_hit *hit)
// {
// 	t_vect3	cmid;
// 	t_vect3	mr;

// 	cmid = vect_add(hit->object->position,\
// 		v_c_prod(hit->object->orientation, (hit->object->distance / 2.0)));
// 	mr = vect_sub(hit->p, cmid);
// 	hit->n = normalize(vect_sub(mr,\
// 		v_c_prod(hit->object->orientation, ((1.0f -\
// 		powf(hit->object->radius2, 2.0) / powf(hit->object->radius1, 2.0)) *\
// 		dot(mr, hit->object->orientation)))));
// }

t_vect3			ellipsoid_normal(t_object *object, t_ray *ray)
{
	t_vect3	cmid;
	t_vect3	mr;
	t_vect3	n;

	cmid = vect_add(object->position, v_c_prod(object->orientation, (object->distance / 2.0)));
	mr = vect_sub(ray->hit_point, cmid);
	n = normalize(vect_sub(mr,\
		v_c_prod(object->orientation, ((1.0f -\
		powf(object->radius2, 2.0) / powf(object->radius1, 2.0)) *\
		dot(mr, object->orientation)))));
		return (n);
}
