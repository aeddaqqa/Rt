/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:48:55 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/24 11:26:54 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// void	ft_triangle_hit_check(t_object *tr, t_tri t, t_intersect i, t_ray *ray)
// {
// 	t.q = vect_add(ray->origin, v_c_prod(ray->direction, t.dist2plane));
// 	t.ca = vect_sub(tr->point_c, tr->point_a);
// 	t.qa = vect_sub(t.q, tr->point_a);
// 	i.t = dot(cross(t.ca, t.qa), t.orientation);
// 	t.bc = vect_sub(tr->point_b, tr->point_c);
// 	t.qc = vect_sub(t.q, tr->point_c);
// 	i.t1 = dot(cross(t.bc, t.qc), t.orientation);
// 	t.ab = vect_sub(tr->point_a, tr->point_b);
// 	t.qb = vect_sub(t.q, tr->point_b);
// 	i.t2 = dot(cross(t.ab, t.qb), t.orientation);
// }

// int		ft_triangle_intersect(t_object *triangle, t_ray *ray, double *tmin)
// {
// 	t_tri		t;
// 	t_intersect i;

// 	t.ca = vect_sub(triangle->point_c, triangle->point_a);
// 	t.ba = vect_sub(triangle->point_b, triangle->point_a);
// 	t.orientation = normalize(cross(t.ca, t.ba));
// 	t.distance = dot(t.orientation, triangle->point_a);
// 	t.x = vect_sub(ray->origin, triangle->point_a);
// 	i.a = -1.0 * dot(t.x, t.orientation);
// 	i.b = dot(ray->direction, t.orientation);
// 	t.dist2plane = i.a / i.b;
// 	ft_triangle_hit_check(triangle, t, i, ray);
// 	if (i.t >= 0.0 && i.t1 >= 0.0 && i.t2 >= 0.0)
// 	{
// 		*tmin = t.dist2plane;
// 		return (t.dist2plane);
// 	}
// 	return (0);
// }


double		hit_triangle(t_object *triangle, t_ray *ray)
{
	t_vect3	x;
	t_vect3	ca;
	t_vect3	ba;
	t_vect3	bc;
	t_vect3	ab;
	t_vect3	normal;
	t_vect3	q;
	t_vect3	qa;
	t_vect3	qb;
	t_vect3	qc;
	double	distance;
	double	dist2plane;
	double	a;
	double	b;
	double	t;
	double	t1;
	double	t2;
	double	tmin;

	ca = vect_sub(triangle->point_c, triangle->point_a);
	ba = vect_sub(triangle->point_b, triangle->point_a);
	normal = normalize(cross(ca, ba));
	distance = dot(normal, triangle->point_a);
	// a = ft_dotproduct(ray->direction, normal);
	// b = ft_dotproduct(normal, ft_vectoradd(ray->source, ft_negative(ft_vectormulti(normal, distance))));
	x = vect_sub(ray->origin, triangle->point_a);
	a = -1.0 * dot(x, normal);
	b = dot(ray->direction, normal);
	dist2plane = a / b;
	q = vect_add(ray->origin, v_c_prod(ray->direction, dist2plane));
	ca = vect_sub(triangle->point_c, triangle->point_a);
	qa = vect_sub(q, triangle->point_a);
	t = dot(cross(ca, qa), normal);
	bc = vect_sub(triangle->point_b, triangle->point_c);
	qc = vect_sub(q, triangle->point_c);
	t1 = dot(cross(bc, qc), normal);
	ab = vect_sub(triangle->point_a, triangle->point_b);
	qb = vect_sub(q, triangle->point_b);
	t2 = dot(cross(ab, qb), normal);
	if (t >= 0.0 && t1 >= 0.0 && t2 >= 0.0)
	{
		tmin = dist2plane;
		return (tmin);
	}
	return (-1);
}