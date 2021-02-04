/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_all_cmp_pobjects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:56:28 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 17:27:55 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				all_cmp_valid_for_sphere(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.radius == false ||\
			n.cmp.position == false || n.cmp.translation == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_plane(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_cone(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.height == false || n.cmp.angle == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_cylinder(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.height == false || n.cmp.radius == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_paraboloid(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.dist == false)
		return (-1);
	return (1);
}
