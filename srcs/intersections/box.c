/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:46:57 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/06 17:58:31 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		calc_solu_xy(t_vect3 *t, t_ray *ray, t_vect3 *bnd, int *sign)
{
	t[0].x = (bnd[sign[0]].x - ray->origin.x) * t[2].x;
	t[1].x = (bnd[1 - sign[0]].x - ray->origin.x) * t[2].x;
	t[0].y = (bnd[sign[1]].y - ray->origin.y) * t[2].y;
	t[1].y = (bnd[1 - sign[1]].y - ray->origin.y) * t[2].y;
}

void		calc_solu_xz(t_vect3 *t, t_ray *ray, t_vect3 *bnd, int *sign)
{
	t[0].x = (t[0].y > t[0].x) ? t[0].y : t[0].x;
	t[1].x = (t[1].y < t[1].x) ? t[1].y : t[1].x;
	t[0].z = (bnd[sign[2]].z - ray->origin.z) * t[2].z;
	t[1].z = (bnd[1 - sign[2]].z - ray->origin.z) * t[2].z;
}

void		bias_calc(t_vect3 *t, int *sign)
{
	sign[0] = t[2].x < 0.00001;
	sign[1] = t[2].y < 0.00001;
	sign[2] = t[2].z < 0.00001;
}

void		get_corners(t_vect3 *bnds, t_object *box, t_ray *ray, t_vect3 *t)
{
	bnds[0] = box->corner[0];
	bnds[1] = box->corner[1];
	t[2] = (t_vect3){1.0 / ray->direction.x, 1.0 / ray->direction.y,\
		1.0 / ray->direction.z};
}

double		hit_box(t_object *box, t_ray *ray)
{
	t_vect3	t[3];
	int		sign[3];
	t_vect3	bounds[2];

	get_corners(bounds, box, ray, t);
	bias_calc(t, sign);
	calc_solu_xy(t, ray, bounds, sign);
	if ((t[0].x > t[1].y) || (t[0].y > t[1].x))
		return (-1.0);
	calc_solu_xz(t, ray, bounds, sign);
	if ((t[0].x > t[1].z) || (t[0].z > t[1].x))
		return (-1.0);
	t[0].x = (t[0].z > t[0].x) ? t[0].z : t[0].x;
	t[1].x = (t[1].z < t[1].x) ? t[1].z : t[1].x;
	if (((t[0].x < t[1].x || t[1].x < 0.001) && t[0].x > 0.1))
	{
		ray->t = t[0].x;
		return (t[0].x);
	}
	else if (((t[1].x < t[0].x || t[0].x < 0.001) && t[1].x > 0.1))
	{
		ray->t = t[1].x;
		return (t[1].x);
	}
	return (-1.0);
}
