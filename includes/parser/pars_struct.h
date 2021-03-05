/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:14:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/05 08:45:30 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_STRUCT_H
# define PARS_STRUCT_H

/*
**-----------------------------{structers}---------------------
*/
#define LIMIT_CMP 26
#define LIMIT_ELEMENTS 13

typedef	enum	e_types_cmp
{
	POSITION,
	POINT_A,
	POINT_B,
	POINT_C,
	POINT_D,
	CORNER_A,
	CORNER_B,
	ORIENTATION,
	ROTATION,
	TRANSLATION,
	COLOR,
	ANGLE,
	RADIUS,
	RADIUS_1,
	RADIUS_2,
	HEIGHT,
	DISTANCE,
	REFLEXION,
	TRANSPARENT,
	REF_INDEX,
	MATTER,
	LOOK_AT,
	ORIGIN,
	FOV,
	INTENSITY,
	TEXTURE
}				t_types_cmp;

typedef struct	s_name_tags
{
	char		*elements_o[LIMIT_ELEMENTS];
	char		*elements_c[LIMIT_ELEMENTS];
	char		*components_c[LIMIT_CMP];
	char		*components_o[LIMIT_CMP];
}				t_tags;

typedef struct	s_ocomponent
{
	bool	position;
	bool	color;
	bool	orientation;
	bool	translation;
	bool	rotation;
	bool	radius;
	bool	angle;
	bool	height;
	bool	dist;
	bool	radius1;
	bool	radius2;
	bool	point_a;
	bool	point_b;
	bool	point_c;
	bool	point_d;
	bool	corner_a;
	bool	corner_b;
}				t_ocomponent;

typedef struct	s_lcomponent
{
	bool	position;
	bool	color;
	bool	intensity;
}				t_lcomponent;

typedef struct	s_ccomponent
{
	bool	origin;
	bool	look_at;
	bool	fov;
}				t_ccomponent;

typedef struct	s_node
{
	int					type;
	t_ocomponent		cmp;
	t_ccomponent		cam;
	t_lcomponent		lit;
}				t_node;

typedef struct	s_helper
{
	int					*i;
	char				*str;
}				t_helper;

#endif
