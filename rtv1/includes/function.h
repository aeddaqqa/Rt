/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:33:01 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/09 05:26:51 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "define.h"

/*
** *******************PARSING*****************
*/

void			parse_objects(t_rt *rt, int fd, enum e_object_type type);
void			new_light(t_rt *rt, int fd);
void			stock(t_rt *rt, int fd);
int				check_argument(t_rt *rt, t_obj *obj, char ***s);

/*
** ******************VECT_CALC******************
*/

t_vector		multip_vec_const(t_vector u, double v);
t_vector		multip_vector(t_vector u, t_vector v);
t_vector		add_vector(t_vector u, t_vector v);
t_vector		sub_vector(t_vector u, t_vector v);
t_vector		div_vector(t_vector u, t_vector v);
t_vector		cross_prod(t_vector u, t_vector v);
t_vector		addvec_const(t_vector u, double v);
t_vector		subvec_const(t_vector u, double v);
double			dot_prod(t_vector u, t_vector v);
t_vector		normalize(t_vector vec);

/*
** *******************READ**********************
*/

t_vector		read_vector(char **value);
double			read_scalar(char **value);
t_color			read_color(char **v);
char			**value(t_rt *rt, int fd);

/*
** *******************CAMERA*******************
*/

void			new_camera(t_rt *rt, int fd);

/*
** *******************LIGHTS******************
*/

unsigned int	light_effect(t_rt *rt, t_obj *object, t_ray *ray);

/*
** *********************DRAW**********************
*/

void			draw(t_rt *rt);
double			hit_cylinder(t_obj *rt, t_ray *ray);
double			hit_sphere(t_obj *rt, t_ray *ray);
double			hit_plane(t_obj *rt, t_ray *ray);
double			hit_cone(t_obj *rt, t_ray *ray);

/*
** **********************FREE********************
*/

void			destroy(t_rt *rt, enum e_error type);
int				ft_close(t_rt *rt);
void			free_double_ptr(char ***ptr);

/*
**	*******************ASSERT********************
*/

int				is_scalar(char *id);
int				is_vect(char *id);
int				is_object(char *id);
int				is_hex(char *value);
void			is_valid_object(t_rt *rt, t_obj *obj, enum e_object_type type);

/*
** ****************** COLORS ******************
*/

t_color			multi_cons_color(t_color color, double t);
t_color			multip_color(t_color c1, t_color c2);
t_color			add_color(t_color c1, t_color c2);
t_color			fraction(t_color c, double fract);
t_color			to_rgb(int color);
int				rgb(t_color color);

/*
** ****************** OTHER ******************
*/

double			equa_solu(double a, double b, double delta);
t_vector		plane_normal(t_ray *ray, t_obj *object);
t_vector		cylinder_normal(t_ray *ray, double t, t_obj *object);
t_vector		cone_normal(t_obj *cone, double t, t_ray *ray);
t_vector		rotation_xyz(t_vector v, t_vector a);
#endif
