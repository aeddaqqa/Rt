/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forcobjects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:17:24 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/29 16:37:56 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		check_for_triangle(int type, t_node n)
{
	if (type != ROTATION && type != TRANSLATION && type != COLOR
	&& type != POINT_A && type != POINT_B && type != POINT_C)
		return (-1);
	if (type == POINT_A && n.cmp.point_a == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == POINT_B && n.cmp.point_b == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == POINT_C && n.cmp.point_c == true)
		return (-1);
	return (1);
}

int		check_for_parallelogram(int type, t_node n)
{
	if (type != ROTATION && type != TRANSLATION && type != COLOR
	&& type != POINT_A && type != POINT_B && type != POINT_C && type != POINT_D)
		return (-1);
	if (type == POINT_A && n.cmp.point_a == true)
		return (-1);
	if (type == POINT_D && n.cmp.point_d == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == POINT_B && n.cmp.point_b == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == POINT_C && n.cmp.point_c == true)
		return (-1);
	return (1);
}

int		check_for_box(int type, t_node n)
{
	if (type != CORNER_A && type != TRANSLATION && type != COLOR
	&& type != CORNER_B && type != ROTATION)
		return (-1);
	if (type == CORNER_A && n.cmp.corner_a == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == CORNER_B && n.cmp.corner_b == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	return (1);
}

int		check_for_torus(int type, t_node n)
{
	if (type != POSITION && type != TRANSLATION && type != COLOR
	&& type != RADIUS_1 && type != ROTATION && type != RADIUS_2)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == RADIUS_1 && n.cmp.radius1 == true)
		return (-1);
	else if (type == RADIUS_2 && n.cmp.radius2 == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	return (1);
}

int		check_for_ellipsoid(int type, t_node n)
{
	if (type != POSITION && type != DISTANCE && type != ROTATION
		&& type != TRANSLATION && type != COLOR && type != ORIENTATION
		&& type != RADIUS_1 && type != RADIUS_2)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == DISTANCE && n.cmp.dist == true)
		return (-1);
	else if (type == RADIUS_1 && n.cmp.radius1 == true)
		return (-1);
	else if (type == RADIUS_2 && n.cmp.radius2 == true)
		return (-1);
	return (1);
}
