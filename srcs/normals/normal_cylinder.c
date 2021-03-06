/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:28:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 16:08:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		cylinder_normal(t_object *object, t_ray *ray)
{
	double		m;
	t_vect3	n;
	t_vect3	p;


	m = dot(ray->direction, object->orientation) * ray->t;
	m += dot(vect_sub(ray->origin, object->position), object->orientation);
	p = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
	n = normalize(vect_sub(vect_sub(p, object->position),\
				v_c_prod(object->orientation, m)));
	m = 0.0;
	if (object->height <= 0)
	{
		return (n);
	}
	if (ray->ret < 0)
	{
		n = v_c_prod(object->orientation, -1.0);
		return (n);
	}
	else if (ray->ret > 1)
	{
		n = object->orientation;
		return (n);
	}
	return (n);
}