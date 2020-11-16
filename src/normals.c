/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:38:42 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/21 13:19:28 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_compute_normals(t_hit *hit, t_ray *ray)
{
	t_vec	tmp;
	float	m;
	float	k;

	if (hit->object->id == 2)
		hit->n = vec_norm(vec_sub(hit->p, hit->object->pos));
	else if (hit->object->id == 3)
	{
		tmp = vec_sub(ray->source, hit->object->pos);
		m = vec_dot(ray->direction, vec_scale(hit->object->axis, hit->t))\
				+ vec_dot(tmp, hit->object->axis);
		hit->n = vec_norm(vec_sub(vec_sub(hit->p, hit->object->pos), \
					vec_scale(hit->object->axis, m)));
	}
	else if (hit->object->id == 4)
	{
		tmp = vec_sub(ray->source, hit->object->pos);
		m = vec_dot(ray->direction, vec_scale(hit->object->axis, \
					hit->t)) + vec_dot(tmp, hit->object->axis);
		k = tanf(convert(hit->object->ang) / 2.);
		hit->n = vec_norm(vec_sub(vec_sub(hit->p, hit->object->pos), \
					vec_scale(hit->object->axis, ((1. + (k * k)) * m))));
	}
	else if (hit->object->id == 5)
		hit->n = hit->object->nrml;
}

t_vec		ft_rotate_object(t_vec to_rot, t_vec rot, int invert)
{
	if (invert)
	{
		to_rot = z_rotation(to_rot, -rot.z);
		to_rot = y_rotation(to_rot, -rot.y);
		to_rot = x_rotation(to_rot, -rot.x);
	}
	else
	{
		to_rot = x_rotation(to_rot, rot.x);
		to_rot = y_rotation(to_rot, rot.y);
		to_rot = z_rotation(to_rot, rot.z);
	}
	return (to_rot);
}
