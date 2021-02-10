/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/10 16:16:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				ft_paraboloid_intersect(t_object *pa, t_ray *ray, double *tmin)
{
	t_vect3		x;
	t_intersect	i;

	x = vect_sub(ray->origin, pa->position);
	i.a = dot(ray->direction, ray->direction) -\
		powf(dot(ray->direction, pa->orientation), 2.0);
	i.b = 2.0 * (dot(ray->direction, x) -\
		dot(ray->direction, v_c_prod(pa->orientation,\
		(dot(x, pa->orientation) + (2.0 * pa->distance)))));
	i.c = dot(x, x) - dot(x,\
		v_c_prod(pa->orientation, (dot(x, pa->orientation) +\
		(4.0 * pa->distance))));
	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
	if (i.delta < 0)
		return (0);
	i.delta = sqrtf(i.delta);
	i.t1 = (-i.b + i.delta) / (2 * i.a);
	i.t2 = (-i.b - i.delta) / (2 * i.a);
	return (ft_min_ray(i.t1, i.t2, tmin));
}
