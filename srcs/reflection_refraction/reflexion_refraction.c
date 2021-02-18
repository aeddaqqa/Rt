/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion_refraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:20:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/18 07:24:17 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_ray		reflexion(t_ray ray, t_vect3 norm)
{
	t_ray	newray;
	double	reflect;

	reflect = 2 * dot(norm, ray.direction);
	newray.origin = ray.hit_point;
	newray.direction =\
    normalize(vect_sub(ray.direction, v_c_prod(norm, reflect)));
	newray.hit_point = (t_vect3){0, 0, 0};
	newray.reflect_nb = ray.reflect_nb + 1;
	newray.reflexion_index = ray.reflexion_index;
	newray.flag = ray.flag;
	return (newray);
}

t_ray		refraction(t_ray ray, t_vect3 norm, double n2)
{
	t_ray	newray;
	t_vect3	dir;
	double	c[2];
	double	s[2];

	c[0] = dot(norm, ray.direction);
	s[0] = sqrtf(1 - c[0] * c[0]);
	s[1] = ray.reflexion_index * (((double)s[0]) / n2);
	if (s[1] > 1)
	{
		newray.direction = (t_vect3){0, 0, 0};
		return (newray);
	}
	newray.origin = ray.hit_point;
	newray.reflexion_index = n2;
	newray.hit_point = (t_vect3){0, 0, 0};
	newray.reflect_nb = ray.reflect_nb + 1;
	newray.flag = ray.flag;
	c[1] = sqrtf(1 - s[1] * s[1]);
	dir = normalize(vect_sub(ray.direction, v_c_prod(norm, dot(ray.direction, norm))));
	newray.direction = vect_add(v_c_prod(norm, -c[1]), v_c_prod(dir, s[1]));
	return (newray);
}