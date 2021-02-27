/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:49:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/27 19:31:54 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int 	ft_cylinder_cap(t_ray *ray, double *t, t_vect3 position, t_vect3 n)
{
	float	ddn;
	float	t1;
	t_vect3	dist;
	
	ray->ret = 0;

	ddn = dot(ray->direction, n);
	if (ddn <= 1.0e-6 && ddn >= -1.0e-6)
		return (-1.0);
	dist = vect_sub(position, ray->origin);
	t1 = (dot(dist, n)) / ddn;
	// if (t1 < *t && t1 > 1e-2)
	if (t1 >= 0.0)
	{
		*t = t1;
		if (ddn >= 1e-6)
		{
			ray->ret = 2;
			return (2);
		}
		 	ray->ret = 1;
		return (1);
	}
	return (0);
}

static int	ft_cylinder_cap1(t_object *cylinder, t_ray *ray, double *t, float m1)
{
	ray->ret = 0;
	if (m1 < -cylinder->height)
		return (0);
	if (ft_cylinder_cap(ray, t, v_c_prod(cylinder->orientation, -cylinder->height), v_c_prod(cylinder->orientation, -1.0)))
		{
			ray->ret = -1;
			return (-1);
		}
	return (0);
}

double			hit_cylinder(t_object *cylinder, t_ray *ray)
{
	t_vect3	x;
	float	m0;
	float	m1;
	double  t;

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
		return (-1.0);
	cylinder->cyl.delta = sqrt(cylinder->cyl.delta);
	cylinder->cyl.t1 = (-cylinder->cyl.b + cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	cylinder->cyl.t2 = (-cylinder->cyl.b - cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	if (cylinder->height <= 0)
		return (equa_solu(cylinder->cyl.a, cylinder->cyl.b, cylinder->cyl.delta));
	if (cylinder->cyl.t1 > cylinder->cyl.t2)
	{
		m0 = cylinder->cyl.t1;
		cylinder->cyl.t1 = cylinder->cyl.t2;
		cylinder->cyl.t2 = m0;
	}
	m0 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t1;
	m0 += dot(x, cylinder->orientation);
	m1 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t2;
	m1 += dot(x, cylinder->orientation);
	ray->ret = 0;
    //printf("m0 : %.2f\t  m1 : %.2f\n", m0, m1);
	if (m0 < -cylinder->height)
	{
		if (ft_cylinder_cap1(cylinder, ray, &t, m1))
		{
			ray->ret = 1;
			return (t);
		}
		
		else return -1;
	}
	else if (m0 >= -cylinder->height && m0 <= cylinder->height)
	{
		if (cylinder->cyl.t1 < 1e-6)// || cylinder->cyl.t1 > ray->t)
			return (-1.0);
		return (cylinder->cyl.t1);
	}
	else if (m0 > cylinder->height)
	{
		if (m1 > cylinder->height)
			return (-1.0);
		if (ft_cylinder_cap(ray, &t, v_c_prod(cylinder->orientation, cylinder->height), cylinder->orientation))
			{
				ray->ret = 2;
				return (t);
			}
	}
	return (-1.0);
}




// double		hit_cylinder(t_object *object, t_ray *ray)
// {
// 	double		delta;
// 	double		a;
// 	double		b;
// 	double		c;
// 	t_vect3	oc;

// 	object->orientation = normalize(object->orientation);
// 	oc = vect_sub(ray->origin, object->position);
// 	a = dot(ray->direction, object->orientation);
// 	a = dot(ray->direction, ray->direction) - (a * a);
// 	b = 2 * (dot(ray->direction, oc) -\
// 			dot(ray->direction, object->orientation) *\
// 			dot(oc, object->orientation));
// 	c = dot(oc, object->orientation);
// 	c = dot(oc, oc) - (c * c) - (object->radius * object->radius);
// 	delta = b * b - 4 * a * c;
// 	if (delta < 0)
// 		return (-1);
// 	return (equa_solu(a, b, delta));
// }
