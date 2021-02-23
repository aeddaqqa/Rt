/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:08:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/02/10 19:21:30 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_FUNCTIONS_H
# define CALC_FUNCTIONS_H

double          dot(t_vect3 u, t_vect3 v);
double			ft_magnitude(t_vect3 v);
double          deg_to_rad(double angle);
t_vect3			ft_vector(double x, double y, double z);
t_vect3			normalize(t_vect3 v);
t_vect3			ft_negative(t_vect3 v);
t_vect3			cross(t_vect3 a, t_vect3 b);
t_vect3			vect_add(t_vect3 a, t_vect3 b);
t_vect3			vect_sub(t_vect3 a, t_vect3 b);
t_vect3         vect_div(t_vect3 u, t_vect3 v);
t_vect3         vect_prod(t_vect3 u, t_vect3 v);
t_vect3         v_c_prod(t_vect3 u, double v);
t_vect3         v_c_add(t_vect3 u, double v);

#endif