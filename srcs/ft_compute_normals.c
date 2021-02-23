/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:23:06 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/23 17:08:33 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

// void		ft_compute_normals(t_hit *hit, t_ray *ray)
// {
// 	t_vect3	x;
// 	double	m;

// 	m = 0;
// 	x = (t_vect3){0, 0, 0};
// 	if (hit->object->type == SPHERE)
// 		hit->n = ft_sphere_normal(hit);
// 	else if (hit->object->type == PLANE)
// 		hit->n = ft_plane_normal(hit->object);
// 	else if (hit->object->type == CYLINDER)
// 		ft_computing_cyl_normal(hit, ray, x, m);
// 	else if (hit->object->type == CONE)
// 		hit->n = ft_cone_normal(hit->object, hit->p);
// 	else if (hit->object->type == BOX)
// 		hit->n = ft_box_normal(hit->object, hit->p);
// 	else if (hit->object->type == PARALLELOGRAM)
// 		hit->n = ft_parallelogram_normal(hit->object);
// 	else if (hit->object->type == TRIANGLE)
// 		ft_computing_triangle_normal(hit);
// 	else if (hit->object->type == ELLIPSOID)
// 		ft_computing_ellipsoid_normal(hit);
// 	else if (hit->object->type == PARABOLOID)
// 		ft_computing_paraboloid_normal(hit);
// }