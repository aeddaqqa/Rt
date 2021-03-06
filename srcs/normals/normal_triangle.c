/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:20:21 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/28 17:36:11 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		triangle_normal(t_object *object, t_ray *ray)
{
	t_vect3	ca;
	t_vect3	ba;

	ca = vect_sub(object->point_c, object->point_a);
	ba = vect_sub(object->point_b, object->point_a);
	return (normalize(cross(ba, ca)));
}
