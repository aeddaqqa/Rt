/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:33:01 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 18:39:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "./parser/pars_functions.h"
# include "./calculation/calc_functions.h"
# include "./normals/nor_functions.h"
#include "../srcs/intersections/includes/intersection.h"

int		ft_min_ray(double t1, double t2, double *t);
void		ft_compute_normals(t_hit *hit, t_ray *ray);
t_ray	*ray_init(t_rt *rt, double x, double y);
// int			ft_cylinder_intersect(t_object *cylinder, t_ray *ray, double *tmin);

#endif