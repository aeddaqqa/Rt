/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/10 16:16:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				ft_cone_intersect(t_object *cone, t_ray *ray, double *tmin)
{
	t_vect3		x;
	t_intersect	i;

	x = vect_sub(ray->origin, cone->position);
	i.k = tanf(deg_to_rad(cone->angle) / 2.0);
	i.a = dot(ray->direction, ray->direction) -\
		(1.0 + (i.k * i.k)) * powf(dot(ray->direction, cone->orientation), 2.0);
	i.b = 2.0 * (dot(ray->direction, x) - ((1.0 + (i.k * i.k)) *\
		dot(ray->direction, cone->orientation) * dot(x, cone->orientation)));
	i.c = dot(x, x) - (1.0 + (i.k * i.k)) *\
		powf(dot(x, cone->orientation), 2.0);
	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
	if (i.delta < 0)
		return (0);
	i.delta = sqrtf(i.delta);
	i.t1 = (-i.b + i.delta) / (2 * i.a);
	i.t2 = (-i.b - i.delta) / (2 * i.a);
	return (ft_min_ray(i.t1, i.t2, tmin));
}
