/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/08 16:28:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		ft_cone_init(t_cone *cone, t_object *o, t_ray *r)
{
	double		a;
	double		b;
	double		c;
	t_vect3		x;

	a = pow(dot(r->direction, o->orientation), 2) -\
		pow(cos(o->angle), 2.0);
	x = vect_sub(r->origin, o->position);
	b = 2 * (dot(r->direction, o->orientation) *\
		(dot(x, o->orientation)) - dot(r->direction, x) *\
			pow(cos(o->angle), 2.0));
	c = (pow(dot(x, o->orientation), 2) -\
		dot(x, x) * pow(cos(o->angle), 2.0));
	cone->d.a = a;
	cone->d.b = b;
	cone->d.c = c;
	cone->d.delta = cone->d.b * cone->d.b - 4.0 * cone->d.a * cone->d.c;
}

double			hit_cone(t_object *c, t_ray *r)
{
	t_cone		a;
	t_vect3		cp;
	float		h;
	t_intersect	i;

	ft_cone_init(&a, c, r);
	if (a.d.delta < 0.00001)
		return (-1.0);
	if (c->height <= 0)
		return (equa_solu(a.d.a, a.d.b, a.d.delta));
	i.t = 0.0001;
	i.t1 = (-a.d.b - sqrt(a.d.delta)) / (2 * a.d.a);
	i.t2 = (-a.d.b + sqrt(a.d.delta)) / (2 * a.d.a);
	if ((i.t1 <= i.t2 && i.t1 >= 0.0) || (i.t1 >= 0.0 && i.t2 < 0.0))
		i.t = i.t1;
	else if ((i.t2 <= i.t1 && i.t2 >= 0.0) || (i.t2 >= 0.0 && i.t1 < 0.0))
		i.t = i.t2;
	else
		return (-1);
	cp = vect_add(r->origin, v_c_prod(r->direction, (i.t)));
	h = dot(cp, c->orientation);
	if (h < 0 || h > c->height)
		return (-1.0);
	return (slice_obj(*c, *r, i.t));
}
