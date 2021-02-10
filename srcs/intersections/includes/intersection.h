/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:53 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 18:32:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

int		ft_cylinder_intersect(t_object *cylinder, t_ray *ray, double *tmin);
int		box_intersect(t_object *box, t_ray *ray, double *tmin);
int		ft_cone_intersect(t_object *cone, t_ray *ray, double *tmin);
int		ft_ellipsoid_intersect(t_object *elip, t_ray *ray, double *tmin);
int		ft_parallelogram_intersect(t_object *para, t_ray *ray, double *tmin);
int		ft_plane_intersect(t_object *plane, t_ray *ray, double *tmin);
int		ft_sphere_intersect(t_object *sphere, t_ray *ray, double *tmin);
int		ft_triangle_intersect(t_object *triangle, t_ray *ray, double *tmin);
void	ft_compute_normals(t_hit *hit, t_ray *ray);
#endif