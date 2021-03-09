/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:11:10 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/09 10:46:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	slice_obj(t_object o, t_ray r, double t)
{
	t_point hit;
	t_vect3 normal;
	t_vect3 dist;
	t_vect3 slice;
	double	dot1;

	if ((o.slice_oaxis_check && ft_magnitude(o.slice_oaxis)) ||\
		(o.slice_axis_check && ft_magnitude(o.slice_axis)))
	{
		r.t = t;
		if (o.type == SPHERE || o.type == BOX ||\
		o.type == PARALLELOGRAM || o.type == TRIANGLE)
			o.orientation = (t_vect3){0.0, 1.0, 0.0};
		if (o.slice_axis_check)
			slice = normalize(o.slice_axis);
		else
			slice = vect_prod((t_vect3){90, 90, 90}, normalize(o.slice_oaxis));
		hit = vect_add(r.origin, v_c_prod(r.direction, t));
		normal = cylinder_normal(&o, &r);
		dist = normalize(vect_sub(hit, o.position));
		dot1 = dot(dist, rotation_xyz(o.orientation, slice));
		return (dot1 >= -0.0000000001 ? t : -1.0);
	}
	return (t);
}
