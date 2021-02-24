/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:23:11 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 16:08:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// void		ft_computing_paraboloid_normal(t_hit *hit)
// {
// 	double	m;

// 	m = dot(vect_sub(hit->p, hit->object->position),\
// 		hit->object->orientation);
// 	hit->n = normalize(vect_sub(vect_sub(hit->p, hit->object->position),\
// 	v_c_prod(hit->object->orientation, (m + hit->object->distance))));
// }

t_vect3			paraboloid_normal(t_object *object, t_ray *ray)
{
	double	m;
	t_vect3	n;

	m = dot(vect_sub(ray->hit_point, object->position),\
		object->orientation);
	n = normalize(vect_sub(vect_sub(ray->hit_point, object->position),\
	v_c_prod(object->orientation, (m + object->distance))));
	return (n);
}
