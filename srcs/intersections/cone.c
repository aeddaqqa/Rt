/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/23 16:38:03 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// static void		ft_cone_init(t_cone *a, t_object *c, t_ray *r)
// {
// 	a->anglecos = pow(cos(c->angle), 2.0);
// 	a->anglesin = pow(sin(c->angle), 2.0);
// 	a->pa = (t_vect3){0.0, 0.0, 0.0};
// 	a->va = normalize(vect_sub(a->pa, c->orientation));
// 	a->x = vect_sub(r->origin, a->pa);
// 	a->a = vect_sub(r->direction, v_c_prod(a->va, dot(r->direction, a->va)));
// 	a->b = vect_sub(a->x, v_c_prod(a->va, dot(a->x, a->va)));
// 	a->d.a = a->anglecos * dot(a->a, a->a) -
// 		a->anglesin * dot(r->direction, a->va) * dot(r->direction, a->va);
// 	a->d.b = 2.0 * a->anglecos * dot(a->a, a->b) -
// 		2.0 * a->anglesin * dot(r->direction, a->va) * dot(a->x,
// 				a->va);
// 	a->d.c = a->anglecos * dot(a->b, a->b) -
// 		a->anglesin * dot(a->x, a->va) * dot(a->x, a->va);
// 	a->d.delta = a->d.b * a->d.b - 4.0 * a->d.a * a->d.c;
// }

// int				ft_cone_intersect(t_object *c, t_ray *r, double *t)
// {
// 	t_cone		a;
// 	int			ret;
// 	t_vect3		cp;
// 	float		h;

// 	ft_cone_init(&a, c, r);
// 	if (a.d.delta < 0.00000001)
// 		return (0);
// 	a.d.delta = sqrt(a.d.delta);
// 	ret = ft_min_ray((-a.d.b + a.d.delta) / (2.0 * a.d.a),
// 			(-a.d.b - a.d.delta) / (2.0 * a.d.a), t);
// 	if (!ret || c->height <= 0)
// 		return (ret);
// 	cp = vect_add(r->origin, v_c_prod(r->direction, (*t)));
// 	h = dot(cp, c->orientation);
// 	if (h < 0 || h > c->height)
// 	{
// 		*t = INFINITY;
// 		return (0);
// 	}
// 	return (1);
// }

double		hit_cone(t_object *obj, t_ray *ray)
{
	double		k;
	double		dv;
	double		xv;
	t_delta		d;
	t_vect3	x;

	k = tan(obj->angle / 2.0);
	x = vect_sub(ray->origin, obj->position);
	dv = dot(ray->direction, obj->orientation);
	xv = dot(x, obj->orientation);
	d.a = dot(ray->direction, ray->direction) - ((1 + k * k) * dv * dv);
	d.b = 2.0 * (dot(ray->direction, x) - ((1 + k * k) * xv * dv));
	d.c = dot(x, x) - ((1 + k * k) * xv * xv);
	d.disc = powf(d.b, 2.0) - 4.0 * d.a * d.c;
	if (d.disc < 0)
		return (-1.0);
	return (equa_solu(d.a, d.b, d.disc));
}
