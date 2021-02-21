/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_reflexion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:20:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/19 13:40:05 by nabouzah         ###   ########.fr       */
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
	return (newray);
}
