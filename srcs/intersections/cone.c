/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/27 18:30:08 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		ft_cone_init(t_cone *cone, t_object *o, t_ray *r)
{

	double a = pow(dot(r->direction, o->orientation), 2) - pow(cos(o->angle), 2.0);
	t_vect3 x = vect_sub(r->origin, o->position);
	double b = 2 * (dot(r->direction, o->orientation) * (dot(x, o->orientation)) - dot(r->direction, x) * pow(cos(o->angle), 2.0));
	double c = (pow(dot(x, o->orientation), 2) - dot(x, x) * pow(cos(o->angle), 2.0));
	/*a->anglecos = pow(cos(c->angle), 2.0);
	a->anglesin = pow(sin(c->angle), 2.0);
	a->pa = c->position;
	a->va = normalize(vect_sub(c->position, c->orientation));
	a->x = vect_sub(r->origin, a->pa);
	a->a = vect_sub(r->direction, v_c_prod(a->va, dot(r->direction, a->va)));
	a->b = vect_sub(a->x, v_c_prod(a->va, dot(a->x, a->va)));
	a->d.a = a->anglecos * dot(a->a, a->a) -
		a->anglesin * dot(r->direction, a->va) * dot(r->direction, a->va);
	a->d.b = 2.0 * a->anglecos * dot(a->a, a->b) -
		2.0 * a->anglesin * dot(r->direction, a->va) * dot(a->x,
				a->va);
	a->d.c = a->anglecos * dot(a->b, a->b) -
		a->anglesin * dot(a->x, a->va) * dot(a->x, a->va);
*/
	cone->d.a = a;
	cone->d.b = b;
	cone->d.c = c;
	cone->d.delta = cone->d.b * cone->d.b - 4.0 * cone->d.a * cone->d.c;
}

double			hit_cone(t_object *c, t_ray *r)
{
	t_cone		a;
	int			ret;
	t_vect3		cp;
	float		h;
	double		t;

	ft_cone_init(&a, c, r);
	if (a.d.delta < 0.00001)
		return (-1.0);
	a.d.delta = sqrt(a.d.delta);
	if (c->height <= 0)
		return (equa_solu(a.d.a, a.d.b, a.d.delta));
	t = 0.0001;
	double t1 = (-a.d.b - sqrt(a.d.delta)) / (2 * a.d.a);
   	double  t2 = (-a.d.b + sqrt(a.d.delta)) / (2 * a.d.a);
 	if ((t1 <= t2 && t1 >= 0.0) || (t1 >= 0.0 && t2 < 0.0))
 		t = t1;
 	else if ((t2 <= t1 && t2 >= 0.0) || (t2 >= 0.0 && t1 < 0.0))
 		t = t2;
	else
		return (-1);
	cp = vect_add(r->origin, v_c_prod(r->direction, (t)));
	h = dot(cp, c->orientation);
	if (h < 0 || h > c->height)
		return (-1.0);
	return (t);
}

// double		hit_cone(t_object *obj, t_ray *ray)
// {
// 	double		k;
// 	double		dv;
// 	double		xv;
// 	t_delta		d;
// 	t_vect3	x;

// 	k = tan(obj->angle / 2.0);
// 	x = vect_sub(ray->origin, obj->position);
// 	dv = dot(ray->direction, obj->orientation);
// 	xv = dot(x, obj->orientation);
// 	d.a = dot(ray->direction, ray->direction) - ((1 + k * k) * dv * dv);
// 	d.b = 2.0 * (dot(ray->direction, x) - ((1 + k * k) * xv * dv));
// 	d.c = dot(x, x) - ((1 + k * k) * xv * xv);
// 	d.disc = powf(d.b, 2.0) - 4.0 * d.a * d.c;
// 	if (d.disc < 0)
// 		return (-1.0);
// 	return (equa_solu(d.a, d.b, d.disc));
// }