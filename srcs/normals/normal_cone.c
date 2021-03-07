/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:28:26 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 17:05:53 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			cone_normal(t_object *cone, t_ray *ray)
{
	t_vect3		new;
	t_point		p;
	double		dv_xv[2];
	double		m;
	t_vect3		x;

	p = v_c_prod(ray->direction, ray->t);
	p = vect_add(ray->origin, p);
	x = vect_sub(ray->origin, cone->position);
	dv_xv[0] = dot(ray->direction, cone->orientation);
	dv_xv[1] = dot(x, cone->orientation);
	m = (dv_xv[0] * ray->t + dv_xv[1]) * (1 + powf(tan(cone->angle / 2.0), 2));
	new = v_c_prod(cone->orientation, m);
	new = vect_add(new, cone->position);
	new = vect_sub(p, new);
	if (dot(ray->direction, new) > 0)
		new = v_c_prod(new, -1.0);
	return (normalize(new));
}
