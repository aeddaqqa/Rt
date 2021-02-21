/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/21 10:51:53 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color		refract_color(t_rt *rt, t_ray ray,  t_hit hit, t_light *light)
{
	t_color	refract;
	t_ray	refract_ray;
	t_ray	reflect_ray;

	refract = (t_vect3){0, 0, 0};
	ray.hit_point = hit.p;
	if (hit.object->is_transp != 0 && ray.reflect_nb < MAX_REF)
	{
		if (dot(normalize(hit.n), ray.direction) > 0)
		{
			refract_ray = refraction(ray, v_c_prod(hit.n, -1), 1);
			reflect_ray = reflexion(ray, v_c_prod(hit.n, -1));
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ref_trsp(rt, hit, refract_ray, light);
			else
				refract = ref_trsp(rt, hit, reflect_ray, light);
		}
		else
		{
			refract_ray = refraction(ray, hit.n, ray.reflexion_index);
			reflect_ray = reflexion(ray, hit.n);
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ref_trsp(rt, hit, refract_ray, light);
			else
				refract = ref_trsp(rt, hit, reflect_ray, light);
		}
	}
	return (refract);
}
