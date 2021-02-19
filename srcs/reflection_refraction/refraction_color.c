/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/19 13:31:34 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color		refract_color(t_rt *rt, t_ray ray,  t_hit hit)
{
	t_color	refract;
	t_ray	refract_ray;
	t_ray	reflect_ray;

	refract = (t_vect3){0, 0, 0};
	if (hit.object->is_transp != 0 && (ray.reflect_nb < 1))
	{
		if (dot(normalize(hit.n), ray.direction) > 0)
		{
			refract_ray = refraction(ray, v_c_prod(hit.n, -1), 1);
			reflect_ray = reflexion(ray, v_c_prod(hit.n, -1));
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = raytrace(rt, &hit, &ray);
			else
				refract = raytrace(rt, &hit, &reflect_ray);
		}
		else
		{
			refract_ray = refraction(ray, hit.n, ray.reflexion_index);
			reflect_ray = reflexion(ray, hit.n);
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = raytrace(rt, &hit, &refract_ray);
			else
				refract = raytrace(rt, &hit, &reflect_ray);
		}
	}
	return (refract);
}
