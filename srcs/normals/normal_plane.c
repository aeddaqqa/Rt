/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:53 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/27 19:18:36 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// t_vect3		ft_plane_normal(t_object *plane)
// {
// 	t_vect3	n;

// 	n = plane->orientation;
// 	return (n);
// }

t_vect3	plane_normal(t_object *object, t_ray *ray)
{
	if (dot(ray->direction, object->orientation) < 0)
		return (object->orientation);
	return (v_c_prod(object->orientation, -1));
}