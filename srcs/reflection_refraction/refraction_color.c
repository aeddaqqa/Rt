/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/18 08:27:22 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color       ray_cast(t_ray ray, t_hit *hit);

t_color	refract_color(t_vect3 norm, t_hit *hit, t_ray ray)
{
	t_color refract;
	t_ray refract_ray;

	refract = (t_vect3){0, 0, 0};
	if (hit->object->is_transp != 0 && (ray.reflect_nb < 1))
	{
		if (dot(normalize(norm), ray.direction) > 0)
		{
			refract_ray = refraction(ray, v_c_prod(norm, -1), 1);
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ray_cast(refract_ray, hit);
			else
				refract = ray_cast(reflexion(ray,
					v_c_prod(norm, -1)), hit);
		}
		else
		{
			refract_ray = refraction(ray, norm, ray.reflexion_index);
			if (ft_magnitude(refract_ray.direction) != 0)
				refract = ray_cast(refract_ray, hit);
			else
				refract = ray_cast(reflexion(ray, norm), hit);
		}
	}
	return (refract);
}