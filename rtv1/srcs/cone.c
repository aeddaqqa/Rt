/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 03:52:44 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	cone_normal(t_obj *cone, double t, t_ray *ray)
{
	t_vector	new;
	t_point		p;
	double		dv_xv[2];
	double		m;
	t_vector	x;

	p = multip_vec_const(ray->direction, t);
	p = add_vector(ray->origin, p);
	x = sub_vector(ray->origin, cone->pos);
	dv_xv[0] = dot_prod(ray->direction, cone->vect_ori);
	dv_xv[1] = dot_prod(x, cone->vect_ori);
	m = (dv_xv[0] * t + dv_xv[1]) * (1 + powf(tan(cone->angle / 2.0), 2));
	new = multip_vec_const(cone->vect_ori, m);
	new = add_vector(new, cone->pos);
	new = sub_vector(p, new);
	if (dot_prod(ray->direction, new) > 0)
		new = multip_vec_const(new, -1.0);
	return (normalize(new));
}

double		hit_cone(t_obj *obj, t_ray *ray)
{
	double		k;
	double		dv;
	double		xv;
	t_delta		d;
	t_vector	x;

	k = tan(obj->angle / 2.0);
	x = sub_vector(ray->origin, obj->pos);
	dv = dot_prod(ray->direction, obj->vect_ori);
	xv = dot_prod(x, obj->vect_ori);
	d.a = dot_prod(ray->direction, ray->direction) - ((1 + k * k) * dv * dv);
	d.b = 2.0 * (dot_prod(ray->direction, x) - ((1 + k * k) * xv * dv));
	d.c = dot_prod(x, x) - ((1 + k * k) * xv * xv);
	d.disc = powf(d.b, 2.0) - 4.0 * d.a * d.c;
	if (d.disc < 0)
		return (-1.0);
	return (equa_solu(d.a, d.b, d.disc));
}
