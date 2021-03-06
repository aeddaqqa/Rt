/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:49:37 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/06 18:01:48 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_disk(t_object *disk, t_ray *ray)
{
	t_vect3	tmp;
	t_vect3	p;
	double	t;

	t = (dot(disk->orientation, disk->position) -\
		dot(disk->orientation, ray->origin))\
		/ dot(disk->orientation, ray->direction);
	tmp = vect_add(ray->origin, v_c_prod(ray->direction, t));
	p = vect_sub(tmp, disk->position);
	if (ft_magnitude(p) >= disk->radius)
		return (-1.0);
	if (t > 1e-2)
	{
		ray->t = t;
		return (t);
	}
	return (-1.0);
}
