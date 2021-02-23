/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:20:21 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/28 17:36:11 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_computing_triangle_normal(t_hit *hit)
{
	t_vect3	ca;
	t_vect3	ba;

	ca = vect_sub(hit->object->point_c, hit->object->point_a);
	ba = vect_sub(hit->object->point_b, hit->object->point_a);
	hit->n = normalize(cross(ba, ca));
}
