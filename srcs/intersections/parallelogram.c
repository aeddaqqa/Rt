/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelogram.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:48:42 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/08 16:32:27 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_parallelogram(t_parallelo *a, t_object *para, t_ray *ray)
{
	if (a->a < 1.0e-6)
		return (0);
	a->q = cross(a->t, a->e01);
	a->b = dot(ray->direction, a->q) * a->invdet;
	if (a->b < 1.0e-6)
		return (0);
	if ((a->a + a->b) > 1.0001f)
	{
		a->e23 = vect_sub(para->point_d, para->point_c);
		a->e21 = vect_sub(para->point_b, para->point_c);
		a->p2 = cross(ray->direction, a->e21);
		a->det2 = dot(a->e23, a->p2);
		if (fabs(a->det2) < 1.0e-6)
			return (0);
		a->invdet2 = 1.0 / a->det2;
		a->t2 = vect_sub(ray->origin, para->point_c);
		a->a2 = dot(a->t2, a->p2) * a->invdet2;
		if (a->a2 < 1.0e-6)
			return (0);
		a->q2 = cross(a->t2, a->e23);
		a->b2 = dot(ray->direction, a->q2) * a->invdet2;
		if (a->b2 < 1.0e-6)
			return (0);
	}
	return (1);
}

double		hit_parallelogram(t_object *para, t_ray *ray)
{
	t_parallelo	a;

	a.e01 = vect_sub(para->point_b, para->point_a);
	a.e03 = vect_sub(para->point_d, para->point_a);
	a.p = cross(ray->direction, a.e03);
	a.det = dot(a.e01, a.p);
	if (fabs(a.det) >= 1.0e-6)
	{
		a.invdet = 1.0 / a.det;
		a.t = vect_sub(ray->origin, para->point_a);
		a.a = dot(a.t, a.p) * a.invdet;
		if (!ft_parallelogram(&a, para, ray))
			return (-1.0);
		a.t1 = dot(a.e03, a.q) * a.invdet;
		if (a.t1 > 1.0e-2)
		{
			ray->t = a.t1;
			return (slice_obj(*para, *ray, a.t1));
		}
	}
	return (-1.0);
}
