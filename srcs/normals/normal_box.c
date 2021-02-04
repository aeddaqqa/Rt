/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:49:20 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		ft_box_normal(t_object *box, t_vect3 h)
{
	t_vect3	c;
	t_vect3	d;
	t_vect3	p;
	double	bias;

	bias = 1.00001;
	c = v_c_prod(vect_add(box->corner[0], box->corner[1]), 0.5);
	d = v_c_prod(vect_sub(box->corner[0], box->corner[1]), 0.5);
	d.x = fabs(d.x) * bias;
	d.y = fabs(d.y) * bias;
	d.z = fabs(d.z) * bias;
	p = vect_sub(h, c);
	return (normalize(ft_vector(p.x / d.x, p.y / d.y, p.z / d.z)));
}
