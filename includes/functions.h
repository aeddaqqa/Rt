/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:33:01 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/25 16:05:09 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "./parser/pars_functions.h"
# include "./calculation/calc_functions.h"
# include "./normals/nor_functions.h"
#include "../srcs/intersections/includes/intersection.h"
# include "../srcs/camera/includes/cam_function.h"

double			ft_atod(const char *str);
double		equa_solu(double a, double b, double delta);
double		hit_sphere(t_object *object, t_ray *ray);
double		hit_cone(t_object *obj, t_ray *ray);
double		hit_plane(t_object *object, t_ray *ray);
double		hit_triangle(t_object *triangle, t_ray *ray);
double		hit_cylinder(t_object *object, t_ray *ray);
double		hit_ellipsoid(t_object *elip, t_ray *ray);
double		hit_box(t_object *box, t_ray *ray);
double		hit_paraboloid(t_object *pa, t_ray *ray);
double		hit_disk(t_object *disk, t_ray *ray);
double		hit_parallelogram(t_object *para, t_ray *ray);
t_vect3		ellipsoid_normal(t_object *object, t_ray *ray);
t_vect3		cylinder_normal(t_object *object, t_ray *ray);
t_vect3		triangle_normal(t_object *object, t_ray *ray);
t_vect3		cone_normal(t_object *cone, t_ray *ray);
t_vect3		plane_normal(t_object *object, t_ray *ray);
t_vect3		sphere_normal(t_object *obj, t_ray *ray);
t_vect3		box_normal(t_object *box, t_ray *h);
t_vect3		paraboloid_normal(t_object *object, t_ray *ray);
t_vect3		normal_disk(t_object *disk, t_ray *ray);
t_vect3		normal_parallelogram(t_object *para, t_ray *ray);

void	menu(t_sdl *sdl, int save);
t_sdl	*init_sdl(void);
void	destroy_sdl(t_sdl **s);
void	render(t_sdl *sdl, t_rt *rt);
int		re_calc(t_sdl *sdl, SDL_Event event);
double     ft_min_ray(double t1, double t2, double *tmin);
void    ft_compute_normals(t_hit *hit, t_ray *ray);
t_ray   obj_intersect(t_object *p, t_hit *hit, t_ray ray, double t);
t_color ft_shade_object(t_hit *hit, t_rt *rt, t_ray *ray);
t_ray   reflexion(t_ray ray, t_vect3 norm);
t_ray   refraction(t_ray ray, t_vect3 norm, double n2);
// t_vect3 lit_comp(t_light *light, t_hit *hit, t_ray *ray);
t_color raytrace(t_rt *rt, t_hit *hit, t_ray *ray);
t_color	refract_color(t_rt *rt, t_ray ray, t_object* object, t_light *light);
t_color reflex_col(t_rt *rt, t_ray ray, t_object* object, t_light *light);
t_color ref_trsp(t_rt *rt, t_object *object, t_ray reflect, t_light *light);
#endif