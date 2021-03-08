/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:48:55 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/08 16:30:27 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double			hit_triangle(t_object *triangle, t_ray *ray)
{
	t_tri		tr;
	t_intersect	i;

	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
	tr.ba = vect_sub(triangle->point_b, triangle->point_a);
	tr.orientation = normalize(cross(tr.ca, tr.ba));
	tr.distance = dot(tr.orientation, triangle->point_a);
	tr.x = vect_sub(ray->origin, triangle->point_a);
	tr.a = -1.0 * dot(tr.x, tr.orientation);
	tr.b = dot(ray->direction, tr.orientation);
	tr.dist2plane = tr.a / tr.b;
	tr.q = vect_add(ray->origin, v_c_prod(ray->direction, tr.dist2plane));
	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
	tr.qa = vect_sub(tr.q, triangle->point_a);
	i.t = dot(cross(tr.ca, tr.qa), tr.orientation);
	tr.bc = vect_sub(triangle->point_b, triangle->point_c);
	tr.qc = vect_sub(tr.q, triangle->point_c);
	i.t1 = dot(cross(tr.bc, tr.qc), tr.orientation);
	tr.ab = vect_sub(triangle->point_a, triangle->point_b);
	tr.qb = vect_sub(tr.q, triangle->point_b);
	i.t2 = dot(cross(tr.ab, tr.qb), tr.orientation);
	if (i.t >= 0.0 && i.t1 >= 0.0 && i.t2 >= 0.0)
		return (slice_obj(*triangle, *ray, tr.dist2plane));
	return (-1);
}
