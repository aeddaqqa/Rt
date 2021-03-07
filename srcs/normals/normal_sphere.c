/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:32:20 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 10:32:31 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			sphere_normal(t_object *obj, t_ray *ray)
{
	t_vect3		n;

	n = normalize(vect_sub(ray->hit_point, obj->position));
	return (n);
}
