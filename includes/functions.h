/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:33:01 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/22 16:27:32 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "./parser/pars_functions.h"
# include "./calculation/calc_functions.h"
# include "./normals/nor_functions.h"
#include "../srcs/intersections/includes/intersection.h"
# include "../srcs/camera/includes/cam_function.h"

void	menu(t_sdl *sdl, int save);
t_sdl	*init_sdl(void);
void	destroy_sdl(t_sdl **s);
void	render(t_sdl *sdl);
int		re_calc(t_sdl *sdl, SDL_Event event);
int     ft_min_ray(double t1, double t2, double *t);
void    ft_compute_normals(t_hit *hit, t_ray *ray);
t_ray   obj_intersect(t_object *p, t_hit *hit, t_ray ray, double t);
t_color ft_shade_object(t_hit *hit, t_rt *rt, t_ray *ray);
t_ray   reflexion(t_ray ray, t_vect3 norm);
t_ray   refraction(t_ray ray, t_vect3 norm, double n2);
t_vect3 lit_comp(t_light *light, t_hit *hit, t_ray *ray);
t_color raytrace(t_rt *rt, t_hit *hit, t_ray *ray);
t_color	refract_color(t_rt *rt, t_ray ray, t_hit hit, t_light *light);
t_color reflex_col(t_rt *rt, t_ray ray, t_hit hit, t_light *light);
t_color ref_trsp(t_rt *rt, t_hit hit, t_ray reflect, t_light *light);
#endif