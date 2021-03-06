/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/06 18:13:22 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_plane(t_object *object, t_ray *ray)
{
	double		t;
	double		a;
	double		b;
	t_vect3		oc;

	object->orientation = normalize(object->orientation);
	oc = vect_sub(ray->origin, object->position);
	a = dot(oc, object->orientation);
	b = dot(ray->direction, object->orientation);
	if (b == 0 || a * b >= 0)
		return (-1.0);
	t = -a / b;
	return (t);
}
