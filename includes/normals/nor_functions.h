/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nor_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:39:48 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOR_FUNCTIONS_H
# define NOR_FUNCTIONS_H

t_vect3					ft_plane_normal(t_object *plane);
t_vect3					ft_sphere_normal(t_hit *hit);
void                    ft_computing_cyl_normal(t_hit *hit, t_ray *ray, t_vect3 x, double m);
t_vect3					ft_cone_normal(t_object *cone, t_vect3 p);
t_vect3					ft_box_normal(t_object *box, t_vect3 h);
t_vect3					ft_parallelogram_normal(t_object *para);
void                    ft_computing_ellipsoid_normal(t_hit *hit);
void            		ft_computing_paraboloid_normal(t_hit *hit);
void		            ft_computing_triangle_normal(t_hit *hit);

#endif