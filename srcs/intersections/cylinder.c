/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:49:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/10 16:16:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_cylinder_cap(t_ray *ray, double *t, t_vect3 pos, t_vect3 n)
{
	double	ddn;
	double	t1;
	t_vect3	dist;

	ddn = dot(ray->direction, n);
	if (ddn <= 1.0e-6 && ddn >= -1.0e-6)
		return (0);
	dist = vect_sub(pos, ray->origin);
	t1 = (dot(dist, n)) / ddn;
	if (t1 >= 0.0)
	{
		*t = t1;
		if (ddn >= 1e-6)
			return (2);
		return (1);
	}
	return (0);
}

static int	ft_cylinder_cap1(t_object *cyl, t_ray *ray, double *t, double m1)
{
	if (m1 < -cyl->height)
		return (0);
	if (ft_cylinder_cap(ray, t, v_c_prod(cyl->orientation, -cyl->height),\
	v_c_prod(cyl->orientation, -1.0)))
		return (-1);
	return (0);
}

int			ft_cylinder_caping(t_object *cyl, t_ray *ray, t_cap c, double *tmin)
{
	if (c.m0 < -cyl->height)
		return (ft_cylinder_cap1(cyl, ray, tmin, c.m1));
	else if (c.m0 >= -cyl->height && c.m0 <= cyl->height)
	{
		if (cyl->cyl.t1 < 1e-6 || cyl->cyl.t1 > *tmin)
			return (0);
		*tmin = cyl->cyl.t1;
		return (1);
	}
	else if (c.m0 > cyl->height)
	{
		if (c.m1 > cyl->height)
			return (0);
		if (ft_cylinder_cap(ray, tmin,\
		v_c_prod(cyl->orientation, cyl->height), cyl->orientation))
			return (2);
	}
	return (0);
}

int			ft_cyl_limits(t_object *cylinder, t_ray *ray, t_vect3 x, double *tmin)
{
	t_cap	c;

	if (cylinder->cyl.t1 > cylinder->cyl.t2)
	{
		c.m0 = cylinder->cyl.t1;
		cylinder->cyl.t1 = cylinder->cyl.t2;
		cylinder->cyl.t2 = c.m0;
	}
	c.m0 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t1;
	c.m0 += dot(x, cylinder->orientation);
	c.m1 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t2;
	c.m1 += dot(x, cylinder->orientation);
	if (!ft_cylinder_caping(cylinder, ray, c, tmin))
		return (0);
	return (1);
}

int			ft_cylinder_intersect(t_object *cylinder, t_ray *ray, double *tmin)
{
	t_vect3	x;

	x = vect_sub(ray->origin, cylinder->position);
	cylinder->cyl.a = dot(ray->direction, ray->direction) -\
	pow(dot(ray->direction, cylinder->orientation), 2.0);
	cylinder->cyl.b = 2.0 * (dot(ray->direction, x) -\
	(dot(ray->direction, cylinder->orientation) *\
	dot(x, cylinder->orientation)));
	cylinder->cyl.c = dot(x, x) -\
	pow(dot(x, cylinder->orientation), 2.0) -\
	(cylinder->radius * cylinder->radius);
	cylinder->cyl.delta = (cylinder->cyl.b * cylinder->cyl.b) -\
	(4.0 * cylinder->cyl.a * cylinder->cyl.c);
	if (cylinder->cyl.delta < 0)
		return (0);
	cylinder->cyl.delta = sqrt(cylinder->cyl.delta);
	cylinder->cyl.t1 = (-cylinder->cyl.b + cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	cylinder->cyl.t2 = (-cylinder->cyl.b - cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	if (cylinder->height <= 0)
		return (ft_min_ray(cylinder->cyl.t1, cylinder->cyl.t2, tmin));
	if (cylinder->cyl.t1 > cylinder->cyl.t2)
		return (ft_cyl_limits(cylinder, ray, x, tmin));
	return (0);
}
