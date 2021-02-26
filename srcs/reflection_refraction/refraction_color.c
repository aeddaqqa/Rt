/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/25 16:04:54 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color		refract_color(t_rt *rt, t_ray ray,  t_object *object, t_light *light)
{
	t_color	refract;
	t_ray	refract_ray;
	t_ray	reflect_ray;

	refract = (t_vect3){0, 0, 0};
	if (object->is_transp != 0 && ray.reflect_nb < MAX_REF)
	{
		if (dot(normalize(object->normal), ray.direction) > 0)
		{
			refract_ray = refraction(ray, v_c_prod(object->normal, -1), 1);
			reflect_ray = reflexion(ray, v_c_prod(object->normal, -1));
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ref_trsp(rt, object, refract_ray, light);
			else
				refract = ref_trsp(rt, object, reflect_ray, light);
		}
		else
		{
			refract_ray = refraction(ray, object->normal, ray.reflexion_index);
			reflect_ray = reflexion(ray, object->normal);
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ref_trsp(rt, object, refract_ray, light);
			else
				refract = ref_trsp(rt, object, reflect_ray, light);
		}
	}
	return (refract);
}
