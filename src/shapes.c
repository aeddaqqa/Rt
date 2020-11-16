/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:16 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/26 13:31:56 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_min_ray(float t1, float t2, float *t)
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
	return (0);
}

int		hit_sphere(t_mlx *p, t_ray *ray, float *tmin)
{
	t_delt	d;

	d.x = vec_sub(ray->source, p->pos);
	d.a = vec_dot(ray->direction, ray->direction);
	d.b = 2.0 * vec_dot(ray->direction, d.x);
	d.c = vec_dot(d.x, d.x) - p->r * p->r;
	d.delta = (d.b * d.b) - (4.0 * d.a * d.c);
	if (d.delta < 0)
		return (0);
	d.delta = sqrtf(d.delta);
	d.t1 = (-d.b + d.delta) / (2 * d.a);
	d.t2 = (-d.b - d.delta) / (2 * d.a);
	return (ft_min_ray(d.t1, d.t2, tmin));
}

int		hit_cylinder(t_mlx *p, t_ray *ray, float *tmin)
{
	t_delt	d;

	d.x = vec_sub(ray->source, p->pos);
	d.a = vec_dot(ray->direction, ray->direction) - \
		powf(vec_dot(ray->direction, p->axis), 2.0);
	d.b = 2.0 * (vec_dot(ray->direction, d.x) - \
			vec_dot(ray->direction, p->axis) * vec_dot(d.x, p->axis));
	d.c = vec_dot(d.x, d.x) - powf(vec_dot(d.x, p->axis), 2.0) - p->r * p->r;
	d.delta = (d.b * d.b) - (4.0 * d.a * d.c);
	if (d.delta < 0)
		return (0);
	d.delta = sqrtf(d.delta);
	d.t1 = (-d.b + d.delta) / (2 * d.a);
	d.t2 = (-d.b - d.delta) / (2 * d.a);
	return (ft_min_ray(d.t1, d.t2, tmin));
}

int		hit_cone(t_mlx *p, t_ray *ray, float *tmin)
{
	t_delt	d;
	float	c;

	d.x = vec_sub(ray->source, p->pos);
	d.k = tanf(convert(p->ang) / 2.);
	d.a = vec_dot(ray->direction, ray->direction) - (1. + d.k * d.k) * \
		powf(vec_dot(ray->direction, p->axis), 2.);
	d.b = 2.0 * (vec_dot(ray->direction, d.x) - ((1. + d.k * d.k) * \
				vec_dot(ray->direction, p->axis) * vec_dot(d.x, p->axis)));
	c = vec_dot(d.x, d.x) - (1. + d.k * d.k) * powf(vec_dot(d.x, p->axis), 2.);
	d.delta = (d.b * d.b) - (4.0 * d.a * c);
	if (d.delta < 0)
		return (0);
	d.delta = sqrtf(d.delta);
	d.t1 = (-d.b + d.delta) / (2 * d.a);
	d.t2 = (-d.b - d.delta) / (2 * d.a);
	return (ft_min_ray(d.t1, d.t2, tmin));
}

int		hit_plane(t_mlx *p, t_ray *ray, float *tmin)
{
	t_delt	d;

	d.x = vec_sub(ray->source, p->pos);
	d.a = -1. * vec_dot(d.x, p->nrml);
	d.b = vec_dot(ray->direction, p->nrml);
	if (fabs(d.b) <= 1e-6)
		return (0);
	d.t1 = d.a / d.b;
	if (d.t1 > 1e-2 && d.t1 < *tmin)
	{
		*tmin = d.t1;
		return (1);
	}
	return (0);
}
