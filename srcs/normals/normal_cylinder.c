/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:28:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 16:08:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_cylinder_normal(t_hit *hit, t_ray *ray, int ret)
{
	double	m;

	m = 0.0;
	if (ret < 0)
		hit->n = v_c_prod(hit->object->orientation, -1.0);
	else if (ret > 1)
		hit->n = hit->object->orientation;
	else
	{
		m = dot(ray->direction, hit->object->orientation) * hit->t;
		m += dot(ray->origin, hit->object->orientation);
		hit->n = vect_sub(hit->p, v_c_prod(hit->object->orientation, m));
	}
}

void		ft_computing_cyl_normal(t_hit *hit, t_ray *ray, t_vect3 x, double m)
{
	int		ret;

	ret = 0;
	if (hit->object->height > 0.0)
	{
		if (!(ret = ft_cylinder_intersect(hit->object, ray, &hit->t)))
			return ;
		ft_cylinder_normal(hit, ray, ret);
	}
	else
	{
		x = vect_sub(ray->origin, hit->object->position);
		m = dot(ray->direction,\
			v_c_prod(hit->object->orientation, hit->t)) + \
			dot(x, hit->object->orientation);
		hit->n = normalize(vect_sub(vect_sub(hit->p,\
			hit->object->position), v_c_prod(hit->object->orientation, m)));
	}
}