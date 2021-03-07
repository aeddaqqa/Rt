/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_ellipsoid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:23:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 10:24:01 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			ellipsoid_normal(t_object *object, t_ray *ray)
{
	t_vect3		cmid;
	t_vect3		mr;
	t_vect3		n;

	cmid = vect_add(object->position, v_c_prod(object->orientation,\
		(object->distance / 2.0)));
	mr = vect_sub(ray->hit_point, cmid);
	n = normalize(vect_sub(mr,\
		v_c_prod(object->orientation, ((1.0f -\
		powf(object->radius2, 2.0) / powf(object->radius1, 2.0)) *\
		dot(mr, object->orientation)))));
	return (n);
}
