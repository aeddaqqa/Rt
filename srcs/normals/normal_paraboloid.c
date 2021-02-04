/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:23:11 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_computing_paraboloid_normal(t_hit *hit)
{
	double	m;

	m = dot(vect_sub(hit->p, hit->object->position),\
		hit->object->axis);
	hit->n = normalize(vect_sub(vect_sub(hit->p, hit->object->position),\
	v_c_prod(hit->object->axis, (m + hit->object->distance))));
}
