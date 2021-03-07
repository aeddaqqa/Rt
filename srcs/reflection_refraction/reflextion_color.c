/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflextion_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 18:02:50 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color	reflex_col(t_rt *rt, t_ray ray, t_object *object, t_light *light)
{
	t_color refl;
	t_ray	reflect;

	refl = (t_color){0, 0, 0};
	if (ray.reflect_nb < MAX_REF && object->is_ref != 0)
	{
		reflect = reflexion(ray, object->normal);
		refl = ref_trsp(rt, object, reflect, light);
	}
	return (refl);
}
