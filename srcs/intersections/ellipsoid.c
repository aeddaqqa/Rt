/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:02 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				ft_ellipsoid_intersect(t_object *elip, t_ray *ray, double *tmin)
{
	t_vect3		x;
	t_intersect	i;
	double		r;
	double		a1;
	double		a2;

	x = vect_sub(ray->origin, elip->position);
	r = elip->radius1 + elip->radius2;
	a1 = 2.0 * elip->distance * dot(ray->direction, elip->axis);
	a2 = (r * r) + (2.0 * elip->distance *\
		dot(x, elip->axis)) - elip->distance;
	i.a = (4.0 * r * r * dot(ray->direction, ray->direction)) - a1 * a1;
	i.b = 2.0 * (4.0 * r * r * dot(ray->direction, x)) - (a1 * a2);
	i.c = (4.0 * r * r * dot(x, x)) - a2 * a2;
	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
	if (i.delta < 0)
		return (0);
	i.delta = sqrtf(i.delta);
	i.t1 = (-i.b + i.delta) / (2 * i.a);
	i.t2 = (-i.b - i.delta) / (2 * i.a);
	return (ft_min_ray(i.t1, i.t2, tmin));
}
