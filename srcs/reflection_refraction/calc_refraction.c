/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_refraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:25:35 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/04 16:01:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_ray		refraction(t_ray ray, t_vect3 norm, double n2)
{
	t_ray	newray;
	t_vect3	dir;
	double	c[2];
	double	s[2];

	c[0] = dot(norm, ray.direction);
	s[0] = sqrtf(1 - c[0] * c[0]);
	s[1] = ray.refraction_index * (((double)s[0]) / n2);
	newray.origin = ray.hit_point;
	if (s[1] > 1)
	{
		newray.direction = (t_vect3){0, 0, 0};
		return (newray);
	}
	newray.refraction_index = n2;
	newray.reflect_nb = ray.reflect_nb + 1;
	c[1] = sqrtf(1 - s[1] * s[1]);
	dir = normalize(vect_sub(ray.direction,\
	v_c_prod(norm, dot(ray.direction, norm))));
	newray.direction = vect_add(v_c_prod(norm, -c[1]), v_c_prod(dir, s[1]));
	return (newray);
}
