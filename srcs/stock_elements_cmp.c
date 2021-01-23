/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:49:45 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/23 19:05:19 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

static void				valid_cmp_for_sphere(t_node *n, int type)
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

static void				valid_cmp_for_plane(t_node *n, int type)
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

static void				valid_cmp_for_cone(t_node *n, int type)
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

static void				valid_cmp_for_cylinder(t_node *n, int type)
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

static void				valid_cmp_for_paraboloid(t_node *n, int type)
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

static void				valid_cmp_for_triangle(t_node *n, int type)
{
	if (type == POINT_A)
		n->cmp.point_a = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == POINT_B)
		n->cmp.point_b = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == POINT_C)
		n->cmp.point_c = true;
}

static void				valid_cmp_for_parallelogram(t_node *n, int type)
{
	if (type == POINT_A)
		n->cmp.point_a = true;
	if (type == POINT_D)
		n->cmp.point_d = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == POINT_B)
		n->cmp.point_b = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == POINT_C)
		n->cmp.point_c = true;
}

static void				valid_cmp_for_ellipsoid(t_node *n, int type)
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
	else if (type == RADIUS_1)
		n->cmp.radius1 = true;
	else if (type == RADIUS_2)
		n->cmp.radius2 = true;
}

static void				valid_cmp_for_box(t_node *n, int type)
{
	if (type == CORNER_A)
		n->cmp.corner_a = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == CORNER_B)
		n->cmp.corner_b = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
}

static void				valid_cmp_for_torus(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == RADIUS_1)
		n->cmp.radius1 = true;
	else if (type == RADIUS_2)
		n->cmp.radius2 = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
}

static	void			valid_cmp(t_node *n, int type)
{
	if (n->type == CAMERA)
		valid_forcam(n, type);
	else if (n->type == LIGHT)
		valid_forlight(n, type);
	else
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
	}
}

static	int				all_cmp_valid_for_sphere(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.radius == false ||
			n.cmp.position == false || n.cmp.translation == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_plane(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.orientation == false ||
			n.cmp.position == false || n.cmp.translation == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_cone(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.orientation == false ||
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.height || n.cmp.angle)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_cylinder(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.orientation == false ||
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.height || n.cmp.radius)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_paraboloid(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.orientation == false ||
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.dist == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_triangle(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.point_a == false ||
			n.cmp.point_b == false || n.cmp.translation == false ||
			n.cmp.point_c == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_parallelogram(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.point_a == false ||
			n.cmp.point_b == false || n.cmp.translation == false ||
			n.cmp.point_c == false || n.cmp.point_d == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_box(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.corner_a == false ||
			n.cmp.corner_b == false || n.cmp.translation == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_ellipsoid(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false || n.cmp.orientation == false ||
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.dist == false || n.cmp.radius2 == false|| 
			n.cmp.radius1 == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid_for_torus(t_node n)
{
	if 	(n.cmp.color == false ||
			n.cmp.rotation == false ||
			n.cmp.position == false || n.cmp.translation == false ||
			n.cmp.radius2 == false || n.cmp.radius1 == false)
		return(-1);
	return (1);
}

static	int				all_cmp_valid(t_node n)
{
	if (n.type == CAMERA)
	{
		if ((n.cam.fov == false || n.cam.look_at == false ||
					n.cam.origin == false))
			return (-1);
	}
	else if (n.type == LIGHT)
	{
		if ((n.lit.color == false || n.lit.intensity == false
					|| n.lit.position == false))
			return (-1);
	}
	else if (n.type == SPHERE)
		return (all_cmp_valid_for_sphere(n));
	else if (n.type == PLANE)
		return (all_cmp_valid_for_plane(n));
	else if (n.type == CONE)
		return (all_cmp_valid_for_cone(n));
	else if (n.type == CYLINDER)
		return (all_cmp_valid_for_cylinder(n));
	else if (n.type == ELLIPSOID)
		return (all_cmp_valid_for_ellipsoid(n));
	else if (n.type == PARABOLOID)
		return (all_cmp_valid_for_paraboloid(n));
	else if (n.type == TRIANGLE)
		return (all_cmp_valid_for_triangle(n));
	else if (n.type == BOX)
		return (all_cmp_valid_for_box(n));
	else if (n.type == PARALLELOGRAM)
		return (all_cmp_valid_for_parallelogram(n));
	else if (n.type == TORUS)
		return (all_cmp_valid_for_torus(n));
	return (1);
}

static int				return_val(int v, t_node n, char *comp)
{
	ft_strdel(&comp);
	if (v == 1)
		return (all_cmp_valid(n));
	return (-1);
}

int						stock_elements_cmp(char *s, t_tags tags, t_node n, int *i, void *obje)
{
	int			r;
	char		*comp;
	char		*content;

	white_space(s, i);
	if (!(comp = get_tag(&s[*i], i)))
		return (-1);/*protect*/
	if (!ft_strcmp(comp, tags.elements_c[n.type]))
		return (return_val(1, n, comp));
	if ((r = check_openning_elem(comp, tags.components_o)) < 0)
		return (return_val(2, n, comp));
	if ((check_components_exist(n, r)) == -1)
		return (return_val(3, n, comp));
	valid_cmp(&n, r);
	ft_strdel(&comp);
	if ((!(content = inner_text(&s[*i], i))) || (stock_cmp(&obje, content, r, n.type)) < 0)
	{
		if (content)
			free(content);
		return (-1);
	}
	free(content);
	if (check_closing_elem(&s[*i], r, tags.components_c, i) < 0)
		return (-1);
	return (stock_elements_cmp(s, tags, n, i, obje));
}
