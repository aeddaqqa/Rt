/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/03 16:42:29 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

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
#endif
