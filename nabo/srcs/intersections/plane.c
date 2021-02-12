/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/10 16:16:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			ft_plane_intersect(t_object *plane, t_ray *ray, double *tmin)
{
	t_vect3	x;
	double	a;
	double	b;
	double	t;

	x = vect_sub(ray->origin, plane->position);
	a = -1.0 * dot(x, plane->orientation);
	b = dot(ray->direction, plane->orientation);
	if (fabs(b) <= 1e-6)
		return (0);
	t = a / b;
	if (t > 1e-2 && t < *tmin)
	{
		*tmin = t;
		return (1);
	}
	return (0);
}
