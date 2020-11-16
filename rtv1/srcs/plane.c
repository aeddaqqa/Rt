/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/07 06:02:50 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	plane_normal(t_ray *ray, t_obj *object)
{
	if (dot_prod(ray->direction, object->vect_ori) < 0)
		return (object->vect_ori);
	return (multip_vec_const(object->vect_ori, -1));
}

double		hit_plane(t_obj *object, t_ray *ray)
{
	double		t;
	double		a;
	double		b;
	t_vector	oc;

	object->vect_ori = normalize(object->vect_ori);
	oc = sub_vector(ray->origin, object->pos);
	a = dot_prod(oc, object->vect_ori);
	b = dot_prod(ray->direction, object->vect_ori);
	if (b == 0 || a * b >= 0)
		return (-1.0);
	t = -a / b;
	return (t);
}
