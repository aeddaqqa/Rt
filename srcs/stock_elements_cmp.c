/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:49:45 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/24 17:12:35 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static	int				all_cmp_validforobjects(t_node n)
{
	if (n.type == SPHERE)
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
	return (-1);
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
	else
		return (all_cmp_validforobjects(n));
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
