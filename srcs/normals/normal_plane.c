/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:31:09 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 10:31:20 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	plane_normal(t_object *object, t_ray *ray)
{
	if (dot(ray->direction, object->orientation) < 0)
		return (object->orientation);
	return (v_c_prod(object->orientation, -1));
}
