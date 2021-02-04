/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_parallelogram.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:16:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/28 17:35:14 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		ft_parallelogram_normal(t_object *para)
{
	t_vect3	n;

	n = cross(vect_sub(para->point_c, para->point_a),\
	vect_sub(para->point_d, para->point_a));
	return (normalize(n));
}
