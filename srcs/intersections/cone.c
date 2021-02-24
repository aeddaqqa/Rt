/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/24 16:38:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_cone(t_object *obj, t_ray *ray)
{
	double		k;
	double		dv;
	double		xv;
	t_delta		d;
	t_vect3	x;

	k = tan(obj->angle / 2.0);
	x = vect_sub(ray->origin, obj->position);
	dv = dot(ray->direction, obj->orientation);
	xv = dot(x, obj->orientation);
	d.a = dot(ray->direction, ray->direction) - ((1 + k * k) * dv * dv);
	d.b = 2.0 * (dot(ray->direction, x) - ((1 + k * k) * xv * dv));
	d.c = dot(x, x) - ((1 + k * k) * xv * xv);
	d.disc = powf(d.b, 2.0) - 4.0 * d.a * d.c;
	if (d.disc < 0)
		return (-1.0);
	return (equa_solu(d.a, d.b, d.disc));
}