/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflextion_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/21 09:52:30 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color reflex_col(t_rt *rt, t_ray ray, t_hit hit, t_light *light)
{
	t_color refl;
	t_ray	reflect;
	t_hit	hit1;

	refl = (t_color){0, 0, 0};
	if (ray.reflect_nb < MAX_REF && hit.object->is_ref != 0)
	{
		ray.hit_point = hit.p;
		reflect = reflexion(ray, hit.n);
		refl = ref_trsp(rt, hit, reflect, light);
	}
	return (refl);
}
