/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflextion_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:04:17 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/18 08:18:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color	reflex_col(t_vect3 norm, t_hit hit, t_ray ray)
{
	t_color refl;

	refl = (t_color){0, 0, 0};
	if (ray.reflect_nb < 5 && hit.object->is_ref != 0)
	// if (raycast(rt->objects, *ray, &hit))
	// 		{
	// 			if (x == W / 2 && y == H / 2)
	// 			{
	// 				printf("test\n");
	// 			}
	// 			refl = ft_shade_object(&hit, rt->lights, rt->objects, ray);
	// 		}
	return (refl);
}
