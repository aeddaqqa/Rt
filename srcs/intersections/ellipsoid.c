/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:02 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/24 16:16:09 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double			hit_ellipsoid(t_object *elip, t_ray *ray)
{
	t_vect3		x;
	t_intersect	i;
	double		r;
	double		a1;
	double		a2;
	double		tmin;

	x = vect_sub(ray->origin, elip->position);
	r = elip->radius1 + elip->radius2;
	a1 = 2.0 * elip->distance * dot(ray->direction, elip->orientation);
	a2 = (r * r) + (2.0 * elip->distance *\
		dot(x, elip->orientation)) - elip->distance;
	i.a = (4.0 * r * r * dot(ray->direction, ray->direction)) - a1 * a1;
	i.b = 2.0 * (4.0 * r * r * dot(ray->direction, x)) - (a1 * a2);
	i.c = (4.0 * r * r * dot(x, x)) - a2 * a2;
	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
	if (i.delta < 0)
		return (-1);
	i.delta = sqrtf(i.delta);
	if (i.delta < 0)
		return (-1);
	i.t1 = (-i.b + i.delta) / (2 * i.a);
	i.t2 = (-i.b - i.delta) / (2 * i.a);
	if (((i.t1 < i.t2 || i.t2 < 0.001) && i.t1 > 0.1))
	{
		ray->t = i.t1;
		return (i.t1);
	}
	else if (((i.t2 < i.t1 || i.t1 < 0.001) && i.t2 > 0.1))
	{
		ray->t = i.t2;
		return (i.t2);
	}
	return (-1);
}