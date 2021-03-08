/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/08 16:24:24 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	equa_solu(double a, double b, double delta)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0.0) || (t1 >= 0.0 && t2 < 0.0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0.0) || (t2 >= 0.0 && t1 < 0.0))
		return (t2);
	return (-1);
}

double	hit_sphere(t_object *object, t_ray *ray)
{
	t_vect3		oc;
	double		a;
	double		b;
	double		c;
	double		delta;

	oc = vect_sub(ray->origin, object->position);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, oc);
	c = dot(oc, oc) - object->radius * object->radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return (-1.0);
	return (slice_obj(*object, *ray, equa_solu(a, b, delta)));
}
