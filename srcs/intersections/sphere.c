/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/27 18:29:41 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// static int		ft_check_ray(double t1, double t2, double *t)
// {
// 	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
// 	{
// 		*t = t1;
// 		return (1);
// 	}
// 	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
// 	{
// 		*t = t2;
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

// int				ft_sphere_intersect(t_object *sphere, t_ray *ray, double *tmin)
// {
// 	t_vect3		x;

// 	x = vect_sub(ray->origin, sphere->position);
// 	sphere->sph.a = dot(ray->direction, ray->direction);
// 	sphere->sph.b = 2.0 * dot(ray->direction, x);
// 	sphere->sph.c = dot(x, x) - sphere->radius * sphere->radius;
// 	sphere->sph.delta = (sphere->sph.b * sphere->sph.b) -\
// 	(4.0 * sphere->sph.a * sphere->sph.c);
// 	if (sphere->sph.delta < 0)
// 		return (0);
// 	sphere->sph.delta = sqrtf(sphere->sph.delta);
// 	sphere->sph.t1 = (-sphere->sph.b + sphere->sph.delta) / (2 * sphere->sph.a);
// 	sphere->sph.t2 = (-sphere->sph.b - sphere->sph.delta) / (2 * sphere->sph.a);
// 	return (ft_check_ray(sphere->sph.t1, sphere->sph.t2, tmin));
// }

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
	// printf("f");
	return (-1);
}

double	hit_sphere(t_object *object, t_ray *ray)
{
	t_vect3		oc;
	double		a;
	double		b;
	double		c;
	double		delta;


	// printf("position = (%lf %lf %lf)\n", object->position.x, object->position.y, object->position.z);
	// printf("radius = (%lf)\n", object->radius);
	oc = vect_sub(ray->origin, object->position);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, oc);
	c = dot(oc, oc) - object->radius * object->radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return (-1.0);
	return (equa_solu(a, b, delta));
}
