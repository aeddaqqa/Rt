/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int		ft_check_ray(double t1, double t2, double *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
}

int				ft_sphere_intersect(t_object *sphere, t_ray *ray, double *tmin)
{
	t_vect3		x;

	x = vect_sub(ray->origin, sphere->position);
	sphere->sph.a = dot(ray->direction, ray->direction);
	sphere->sph.b = 2.0 * dot(ray->direction, x);
	sphere->sph.c = dot(x, x) - sphere->radius * sphere->radius;
	sphere->sph.delta = (sphere->sph.b * sphere->sph.b) -\
	(4.0 * sphere->sph.a * sphere->sph.c);
	if (sphere->sph.delta < 0)
		return (0);
	sphere->sph.delta = sqrtf(sphere->sph.delta);
	sphere->sph.t1 = (-sphere->sph.b + sphere->sph.delta) / (2 * sphere->sph.a);
	sphere->sph.t2 = (-sphere->sph.b - sphere->sph.delta) / (2 * sphere->sph.a);
	return (ft_check_ray(sphere->sph.t1, sphere->sph.t2, tmin));
}
