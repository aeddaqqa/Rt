/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:00 by chzabakh          #+#    #+#             */
/*   Updated: 2020/11/07 09:56:05 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../get_next_line/get_next_line.h"
# include <math.h>
# include <mlx.h>
# define WIN_W 1280
# define WIN_H 720

typedef	struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef	struct	s_clr
{
	int	r;
	int	g;
	int	b;
}				t_clr;

typedef	struct	s_err
{
	int	ch;
	int	err;
	int	i;
}				t_err;

typedef	struct	s_delt
{
	t_vec	x;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
	float	k;
}				t_delt;

typedef struct	s_cam
{
	t_vec	pos;
	t_vec	lkat;
	t_vec	fwd;
	t_vec	vup;
	t_vec	u;
	t_vec	v;
	t_vec	lwr_lft_crnr;
	t_vec	hrzntl;
	t_vec	vrtcl;
	float	fov;
}				t_cam;

typedef	struct	s_mlx
{
	int				id;
	t_vec			pos;
	t_vec			rot;
	t_vec			tr;
	t_vec			dir;
	t_vec			clr;
	t_vec			axis;
	t_vec			nrml;
	float			ang;
	float			ntnst;
	float			r;
	struct s_mlx	*next;
}				t_mlx;

typedef struct	s_ray
{
	t_vec	source;
	t_vec	direction;
}				t_ray;

typedef struct	s_hit
{
	t_vec	n;
	t_vec	p;
	t_mlx	*object;
	float	t;
}				t_hit;

typedef	struct	s_raysave
{
	t_ray	ray;
	t_ray	save;
}				t_raysave;

typedef	struct	s_settings
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_str;
	int		bpp;
	int		l;
	int		endin;
	t_cam	cam;
}				t_settings;

typedef	struct	s_main
{
	char	*line;
	int		fd;
	t_mlx	*head;
	t_mlx	*tmp;
}				t_main;

t_vec			vec_add(t_vec vec1, t_vec vec2);
t_vec			vec_sub(t_vec vec1, t_vec vec2);
float			vec_dot(t_vec vec1, t_vec vec2);
t_vec			vec_cross(t_vec vec1, t_vec vec2);
t_vec			vec_scale(t_vec vec1, float scale);
float			vec_len(t_vec vec1);
t_vec			vec_norm(t_vec vec1);
void			ft_stock(char *line, t_mlx *node);
void			ft_2dfree(char **tab);
void			ft_lstrmv(t_mlx **head);
int				ft_check(char *line);
int				ft_cor(char *str);
int				ft_clr(char *str);
int				ft_cor(char *str);
int				ft_cornor(char *str);
int				ft_num(char *str);
void			ft_start(t_mlx *hd);
void			ft_camera(t_settings *m, t_mlx *hd);
t_ray			camera_ray(t_cam cam, int x, int y);
int				raycast(t_mlx *lst, t_ray *ray, t_hit *hit);
int				hit_sphere(t_mlx *p, t_ray *ray, float *t);
int				hit_cylinder(t_mlx *p, t_ray *ray, float *t);
int				hit_cone(t_mlx *p, t_ray *ray, float *tmin);
int				hit_plane(t_mlx *p, t_ray *ray, float *tmin);
void			ft_compute_normals(t_hit *hit, t_ray *ray);
int				ft_shade(t_hit *hit, t_mlx *lights, t_mlx *hd, t_ray *ray);
t_vec			amb(t_vec color, t_vec lit_clr, t_vec hit_obj_clr);
int				rgb_to_int(t_vec v);
t_vec			clamp_vec(t_vec v);
float			convert(float ang);
t_vec			x_rotation(t_vec v, float theta);
t_vec			y_rotation(t_vec v, float theta);
t_vec			z_rotation(t_vec v, float theta);
t_vec			ft_rotate_object(t_vec to_rot, t_vec rot, int invert);
t_ray			ft_transform_ray(t_mlx *obj, t_ray *raw, int invert);
#endif
