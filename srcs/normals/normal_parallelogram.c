/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_parallelogram.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:29:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 18:05:38 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			normal_parallelogram(t_object *para, t_ray *ray)
{
	t_vect3		n;

	(void)ray;
	n = cross(vect_sub(para->point_c, para->point_a),\
	vect_sub(para->point_d, para->point_a));
	return (normalize(n));
}
