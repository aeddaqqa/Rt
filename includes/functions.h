/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/04 23:22:31 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void		raytrace(t_rt *rt, int *data);



/*
**		calc vect
*/
double		dot_prod(t_vect3 u, t_vect3 v);
t_vect3		add_vector(t_vect3 u, t_vect3 v);
t_vect3		sub_vector(t_vect3 u, t_vect3 v);
t_vect3		multip_vector(t_vect3 u, t_vect3 v);
t_vect3		div_vector(t_vect3 u, t_vect3 v);
t_vect3		cross_prod(t_vect3 u, t_vect3 v);
t_vect3		addvec_const(t_vect3 u, double v);
t_vect3		subvec_const(t_vect3 u, double v);
t_vect3		multip_vec_const(t_vect3 u, double v);
/*
**
*/
#endif
