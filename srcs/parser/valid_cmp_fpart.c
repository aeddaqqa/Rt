/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmp_fpart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:36:20 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/22 16:03:25 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static	void			valid_forcam(t_node *n, int type)
{
	if (type == ORIGIN)
		n->cam.origin = true;
	else if (type == LOOK_AT)
		n->cam.look_at = true;
	else if (type == FOV)
		n->cam.fov = true;
}

static	void			valid_forlight(t_node *n, int type)
{
	if (type == POSITION)
		n->lit.position = true;
	else if (type == INTENSITY)
		n->lit.intensity = true;
	else if (type == COLOR)
		n->lit.color = true;
}

static void				valid_forobjects(t_node *n, int type)
{
	if (n->type == SPHERE)
		valid_cmp_for_sphere(n, type);
	else if (n->type == PLANE)
		valid_cmp_for_plane(n, type);
	else if (n->type == CONE)
		valid_cmp_for_cone(n, type);
	else if (n->type == CYLINDER)
		valid_cmp_for_cylinder(n, type);
	else if (n->type == ELLIPSOID)
		valid_cmp_for_ellipsoid(n, type);
	else if (n->type == PARABOLOID)
		valid_cmp_for_paraboloid(n, type);
	else if (n->type == TRIANGLE)
		valid_cmp_for_triangle(n, type);
	else if (n->type == BOX)
		valid_cmp_for_box(n, type);
	else if (n->type == PARALLELOGRAM)
		valid_cmp_for_parallelogram(n, type);
	else if (n->type == TORUS)
		valid_cmp_for_torus(n, type);
	else if (n->type == DISK)
		valid_cmp_for_disk(n, type);
}

void					valid_cmp(t_node *n, int type)
{
	if (n->type == CAMERA)
		valid_forcam(n, type);
	else if (n->type == LIGHT)
		valid_forlight(n, type);
	else
		valid_forobjects(n, type);
}
