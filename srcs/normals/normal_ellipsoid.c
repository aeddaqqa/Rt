/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_ellipsoid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:21:54 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/28 17:27:33 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_computing_ellipsoid_normal(t_hit *hit)
{
	t_vect3	cmid;
	t_vect3	mr;

	cmid = vect_add(hit->object->position,\
		v_c_prod(hit->object->axis, (hit->object->distance / 2.0)));
	mr = vect_sub(hit->p, cmid);
	hit->n = normalize(vect_sub(mr,\
		v_c_prod(hit->object->axis, ((1.0f -\
		powf(hit->object->radius2, 2.0) / powf(hit->object->radius1, 2.0)) *\
		dot(mr, hit->object->axis)))));
}
