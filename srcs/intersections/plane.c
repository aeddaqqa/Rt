/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/23 16:37:37 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// int			ft_plane_intersect(t_object *plane, t_ray *ray, double *tmin)
// {
// 	t_vect3	x;
// 	double	a;
// 	double	b;
// 	double	t;

// 	x = vect_sub(ray->origin, plane->position);
// 	a = -1.0 * dot(x, plane->orientation);
// 	b = dot(ray->direction, plane->orientation);
// 	if (fabs(b) <= 1e-6)
// 		return (0);
// 	t = a / b;
// 	if (t > 1e-2 && t < *tmin)
// 	{
// 		*tmin = t;
// 		return (1);
// 	}
// 	return (0);
// }

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
