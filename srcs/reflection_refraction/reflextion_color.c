/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflextion_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/19 13:23:37 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color reflex_col(t_rt *rt, t_ray ray, t_hit hit)
{
	t_color refl;
	t_ray	reflect;

	refl = (t_color){0, 0, 0};
	if (ray.reflect_nb < 5 && hit.object->is_ref != 0)
	{
		reflect = reflexion(ray, hit.n);
		refl = raytrace(rt, &hit, &reflect);
	}
	return (refl);
}
