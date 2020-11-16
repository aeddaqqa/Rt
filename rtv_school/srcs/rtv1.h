/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:31:07 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/28 09:54:21 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define BUFF_SIZE 100000

# define WIN_W 1280
# define WIN_H 720

# define ELEMENTS "camera", "light", "sphere", "plane", "cone", "cylinder"

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include "../libft/libft.h"
# include "../linearlib/linear_alg.h"

typedef struct			s_base
{
	int					i;
	int					p;
	int					rt;
	int					n;
	int					somme;
}						t_base;

typedef struct			s_cam
{
	t_vec				pos;
	t_vec				forward;
	t_vec				u;
	t_vec				v;
	t_vec				lower_left_corner;
	t_vec				horizontal;
	t_vec				vertical;
	float				fov;
}						t_cam;

typedef struct			s_ray
{
	t_vec				source;
	t_vec				direction;
}						t_ray;

typedef enum			e_type
{
	NONE,
	SPHERE = 10,
	PLANE,
	CONE,
	CYLINDER
}						t_type;

typedef struct			s_object
{
	t_type				type;
	t_vec				pos;
	t_vec				trans;
	t_vec				rot;
	t_vec				color;
	float				radius;
	float				angle;
	t_vec				normal;
	t_vec				axis;
	struct s_object		*next;
}						t_object;

typedef struct			s_light
{
	t_vec				pos;
	t_vec				color;
	float				intensity;
	struct s_light		*next;
}						t_light;

typedef struct			s_hit
{
	t_vec				n;
	t_vec				p;
	t_object			*object;
	float				t;
}						t_hit;

typedef struct			s_mx
{
	void				*mptr;
	void				*wptr;
	void				*iptr;
	int					*rt;
	int					bpp;
	int					size;
	int					end;
	t_object			*objects;
	t_light				*lights;
	t_cam				cam;
}						t_mx;

int						ft_open(char *str, t_mx *v);
void					ft_usage(void);
void					ft_destroy(t_mx *v);
int						key_press(int keycode, void *p);
int						red_button(void *p);
void					setup(t_mx *v);
void					update(t_mx *mx);
void					display(t_mx *mx);
void					run(t_mx *mx);
float					clamp(float value, float min, float max);
t_vec					clamp_vect(t_vec v);
int						rgb_to_int(t_vec v);
int						shadow_cast(t_object *lst, t_ray *ray, float *tmin);
t_object				*ft_object_new(t_object o);
void					ft_object_push(t_object **lst, t_object *nw);
void					ft_object_clear(t_object **lst);
t_light					*ft_light_new(t_vec pos, t_vec color, float intensity);
void					ft_light_push(t_light **lst, t_light *nw);
void					ft_light_clear(t_light **lst);
// the following is a function to push an element at the beginning of a linked_list;

/* void        ft_object_push_front(t_object **lst, t_object *new){

    if (lst == NULL || new == NULL)
    return;
    new->next = *lst;
    *lst = new;
}*/
void					ft_strsplit_free(char ***tab);
int						ft_strsplit_len(char **tab);
void					ft_strsplit_print(char **tab);
int						ft_split_check(char *line);
int						ft_check_vectors(char *str);
int						ft_check_floats(char *str);
int						ft_check_positive_floats(char *str);
int						ft_check_camera_fov(char *str);
int						ft_special_atoi_base(char *str);
t_vec					vect_from_hexa(int rgb);
t_vec					string_to_vect(char *str);
float					deg_to_rad(float angle);
t_vec					x_rotation(t_vec v, float theta);
t_vec					y_rotation(t_vec v, float theta);
t_vec					z_rotation(t_vec v, float theta);
int						ft_parse_sphere(t_mx *v, char **token);
int						ft_parse_plane(t_mx *v, char **token);
int						ft_parse_cone(t_mx *v, char **token);
int						ft_parse_cylinder(t_mx *v, char **token);
int						ft_parse_light(t_mx *v, char **token);
int						ft_parse_camera(t_mx *v, char **token);
t_cam					ft_camera_create(t_vec pos, t_vec at, t_vec vup, \
						float vfov);
t_ray					camera_ray(t_cam *cam, int x, int y);

#endif