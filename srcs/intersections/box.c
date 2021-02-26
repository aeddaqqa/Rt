/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:46:57 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/25 15:51:43 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double			hit_box(t_object *box, t_ray *ray)
{
	t_vect3	t[3];
	int		sign[3];
	t_vect3	bounds[2];

	bounds[0] = box->corner[0];
	bounds[1] = box->corner[1];
	t[2] = (t_vect3){1.0 / ray->direction.x, 1.0 / ray->direction.y, 1.0 / ray->direction.z};
	sign[0] = t[2].x < 0.00001;
	sign[1] = t[2].y < 0.00001;
	sign[2] = t[2].z < 0.00001;
	t[0].x = (bounds[sign[0]].x - ray->origin.x) * t[2].x;
	t[1].x = (bounds[1 - sign[0]].x - ray->origin.x) * t[2].x;
	t[0].y = (bounds[sign[1]].y - ray->origin.y) * t[2].y;
	t[1].y = (bounds[1 - sign[1]].y - ray->origin.y) * t[2].y;
	if ((t[0].x > t[1].y) || (t[0].y > t[1].x))
		return (-1.0);
	t[0].x = (t[0].y > t[0].x) ? t[0].y : t[0].x;
	t[1].x = (t[1].y < t[1].x) ? t[1].y : t[1].x;
	t[0].z = (bounds[sign[2]].z - ray->origin.z) * t[2].z;
	t[1].z = (bounds[1 - sign[2]].z - ray->origin.z) * t[2].z;
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