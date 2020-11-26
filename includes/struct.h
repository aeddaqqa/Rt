/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:31:06 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/09 05:09:24 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"

typedef struct		s_vector
{
	double	x;
	double	y;
	double	z;
}					t_vector;

typedef struct		s_delta
{
	double	a;
	double	b;
	double	c;
	double	disc;
}					t_delta;

typedef struct		s_scord
{
	t_vector	u;
	t_vector	v;
	t_vector	w;
}					t_scord;

typedef	t_vector	t_point;
typedef	t_vector	t_color;

typedef struct		s_cam
{
	t_point		o;
	t_vector	l;
	t_vector	up;
	double		fov;
	double		ratio;
	double		plan_h;
	double		plan_w;
	t_scord		cords;
}					t_cam;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*data;
	int				a;
	int				b;
	int				c;
}					t_mlx;

typedef struct		s_obj
{
	enum e_object_type	type;
	t_point				pos;
	t_vector			vect_ori;
	t_vector			rot;
	t_vector			normal;
	double				rayon;
	t_color				color;
	double				angle;
	double				diffuse;
	double				ambient;
	double				specular;
	struct s_obj		*next;
}					t_obj;

typedef struct		s_light
{
	t_vector		dir;
	t_point			pos;
	double			intensity;
	double			d;
	t_color			color;
	t_vector		light_reflected;
	struct s_light	*next;
}					t_light;

typedef struct		s_ray
{
	t_point		origin;
	t_vector	direction;
	t_point		hit_point;
}					t_ray;

typedef struct		s_rt
{
	t_mlx			*m;
	t_cam			*cam;
	t_light			*lights;
	t_ray			ray;
	t_obj			*objects;
	t_vector		null;
	double			(**hit_object)(t_obj *obj, t_ray *r);
	unsigned int	nbr_lights;
}					t_rt;

#endif
