/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:28:35 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 10:28:56 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			paraboloid_normal(t_object *object, t_ray *ray)
{
	double		m;
	t_vect3		n;

	m = dot(vect_sub(ray->hit_point, object->position),\
		object->orientation);
	n = normalize(vect_sub(vect_sub(ray->hit_point, object->position),\
	v_c_prod(object->orientation, (m + object->distance))));
	return (n);
}
