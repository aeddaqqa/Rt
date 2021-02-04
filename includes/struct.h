/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/03 16:43:34 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_vect3
{
	double		x;
	double		y;
	double		z;
}					t_vect3;

typedef	t_vect3		t_point;
typedef	t_vect3		t_color;

typedef struct		s_light
{
	t_vect3			dir;
	t_point			pos;
	double			intensity;
	double			d;
	t_color			color;
	t_vect3			light_reflected;
	struct s_light	*next;
}					t_light;

typedef struct		s_cam
{
	t_point			o;
	t_vect3			l;
	t_vect3			up;
	double			fov;
	double			ratio;
	double			plan_h;
	double			plan_w;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_object
{
	t_type			type;
	t_point			position;
	t_point			point_a;
	t_point			point_b;
	t_point			point_c;
	t_point			point_d;
	t_point			corner[2];
	t_vect3			orientation;
	t_vect3			rotation;
	t_vect3			translation;
	t_color			color;
	double			radius;
	double			angle;
	double			dist;
	double			radius1;
	double			radius2;
	double			height;
	struct s_object	*next;
}					t_object;

typedef struct		s_rt
{
	t_node			node;
	t_object		*obj;
	bool			save;
	t_object		*objects;
	t_cam			*cameras;
	t_light			*lights;
	double			ambient;
	bool			ambient_exist;
}					t_rt;

#endif
