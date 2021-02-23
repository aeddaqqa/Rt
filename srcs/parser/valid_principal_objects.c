/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_principal_objects.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:41:21 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 17:27:55 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void				valid_cmp_for_sphere(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == RADIUS)
		n->cmp.radius = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
}

void				valid_cmp_for_plane(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
}

void				valid_cmp_for_cone(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == HEIGHT)
		n->cmp.height = true;
	else if (type == ANGLE)
		n->cmp.angle = true;
}

void				valid_cmp_for_cylinder(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == HEIGHT)
		n->cmp.height = true;
	else if (type == RADIUS)
		n->cmp.radius = true;
}

void				valid_cmp_for_paraboloid(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == DISTANCE)
		n->cmp.dist = true;
}
