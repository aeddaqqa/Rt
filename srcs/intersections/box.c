/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:46:57 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			box_intersect(t_object *box, t_ray *ray, double *tmin)
{
	t_vect3	t[3];
	int		sign[3];
	t_vect3	corner[2];

	corner[0] = box->corner[0];
	corner[1] = box->corner[1];
	t[2] = (t_vect3){1.0 / ray->direction.x, 1.0 / ray->direction.y, 1.0 / ray->direction.z};
	sign[0] = t[2].x < 0.00001;
	sign[1] = t[2].y < 0.00001;
	sign[2] = t[2].z < 0.00001;
	t[0].x = (corner[sign[0]].x - ray->origin.x) * t[2].x;
	t[1].x = (corner[1 - sign[0]].x - ray->origin.x) * t[2].x;
	t[0].y = (corner[sign[1]].y - ray->origin.y) * t[2].y;
	t[1].y = (corner[1 - sign[1]].y - ray->origin.y) * t[2].y;
	if ((t[0].x > t[1].y) || (t[0].y > t[1].x))
		return (0);
	t[0].x = (t[0].y > t[0].x) ? t[0].y : t[0].x;
	t[1].x = (t[1].y < t[1].x) ? t[1].y : t[1].x;
	t[0].z = (corner[sign[2]].z - ray->origin.z) * t[2].z;
	t[1].z = (corner[1 - sign[2]].z - ray->origin.z) * t[2].z;
	if ((t[0].x > t[1].z) || (t[0].z > t[1].x))
		return (0);
	t[0].x = (t[0].z > t[0].x) ? t[0].z : t[0].x;
	t[1].x = (t[1].z < t[1].x) ? t[1].z : t[1].x;
	return (ft_min_ray(t[0].x, t[1].x, tmin));
}
