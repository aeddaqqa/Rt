/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forpobjects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:09:24 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:16:57 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int		check_for_sphere(int type, t_node n)
{
	if (type != POSITION && type != COLOR && type != RADIUS && type != ROTATION\
		&& type != TRANSLATION && type != REF_INDEX && type != REFLEXION && \
		type != TRANSPARENT && type != MATTER && \
		type != TEXTURE && type != SLICE)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == RADIUS && n.cmp.radius == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	return (1);
}

int		check_for_plane(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION\
		&& type != TRANSLATION && type != COLOR && type != REF_INDEX\
		&& type != REFLEXION && type != TRANSPARENT && type != MATTER\
		&& type != TEXTURE && type != SLICE)
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
	return (1);
}

int		check_for_cone(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION\
		&& type != TRANSLATION && type != COLOR && type != HEIGHT\
		&& type != ANGLE && type != REF_INDEX\
		&& type != REFLEXION && type != TRANSPARENT && type != MATTER
		&& type != TEXTURE && type != SLICE)
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
	else if (type == HEIGHT && n.cmp.height == true)
		return (-1);
	else if (type == ANGLE && n.cmp.angle == true)
		return (-1);
	return (1);
}

int		check_for_cylinder(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION\
		&& type != TRANSLATION && type != COLOR &&\
		type != HEIGHT && type != RADIUS && type != REF_INDEX\
		&& type != REFLEXION && type != TRANSPARENT && type != MATTER
		&& type != TEXTURE && type != SLICE)
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
	else if (type == HEIGHT && n.cmp.height == true)
		return (-1);
	else if (type == RADIUS && n.cmp.radius == true)
		return (-1);
	return (1);
}

int		check_for_paraboloid(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION\
		&& type != TRANSLATION && type != COLOR && type != DISTANCE &&\
		type != REF_INDEX &&\
		type != REFLEXION && type != TRANSPARENT && type != MATTER && \
		type != TEXTURE && type != SLICE)
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
	return (1);
}
