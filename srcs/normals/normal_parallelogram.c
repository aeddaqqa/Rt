/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_parallelogram.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:29:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 10:30:16 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			normal_parallelogram(t_object *para, t_ray *ray)
{
	t_vect3		n;

	n = cross(vect_sub(para->point_c, para->point_a),\
	vect_sub(para->point_d, para->point_a));
	return (normalize(n));
}
