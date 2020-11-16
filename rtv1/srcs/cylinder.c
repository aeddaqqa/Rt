/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/07 05:46:31 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	cylinder_normal(t_ray *ray, double t, t_obj *object)
{
	double		m;
	t_vector	n;
	t_vector	p;

	m = dot_prod(ray->direction, object->vect_ori) * t;
	m += dot_prod(sub_vector(ray->origin, object->pos), object->vect_ori);
	p = add_vector(ray->origin, multip_vec_const(ray->direction, t));
	n = normalize(sub_vector(sub_vector(p, object->pos),\
				multip_vec_const(object->vect_ori, m)));
	return (n);
}

double		hit_cylinder(t_obj *object, t_ray *ray)
{
	double		delta;
	double		a;
	double		b;
	double		c;
	t_vector	oc;

	object->vect_ori = normalize(object->vect_ori);
	oc = sub_vector(ray->origin, object->pos);
	a = dot_prod(ray->direction, object->vect_ori);
	a = dot_prod(ray->direction, ray->direction) - (a * a);
	b = 2 * (dot_prod(ray->direction, oc) -\
			dot_prod(ray->direction, object->vect_ori) *\
			dot_prod(oc, object->vect_ori));
	c = dot_prod(oc, object->vect_ori);
	c = dot_prod(oc, oc) - (c * c) - (object->rayon * object->rayon);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	return (equa_solu(a, b, delta));
}
