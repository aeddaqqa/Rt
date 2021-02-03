/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_all_cmp_cobjects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:58:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/29 16:44:34 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				all_cmp_valid_for_triangle(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.point_a == false ||\
			n.cmp.point_b == false || n.cmp.translation == false ||\
			n.cmp.point_c == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_parallelogram(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.point_a == false ||\
			n.cmp.point_b == false || n.cmp.translation == false ||\
			n.cmp.point_c == false || n.cmp.point_d == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_box(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.corner_a == false ||\
			n.cmp.corner_b == false || n.cmp.translation == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_ellipsoid(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.dist == false || n.cmp.radius2 == false || \
			n.cmp.radius1 == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_torus(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.radius2 == false || n.cmp.radius1 == false)
		return (-1);
	return (1);
}
