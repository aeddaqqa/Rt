/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:49:45 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/19 18:30:32 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static	void			valid_forcam(t_node *n, int type)
{
	if (type == 5)
		n->cam.origin = true;
	else if (type == 4)
		n->cam.look_at = true;
	else if (type == 6)
		n->cam.fov = true;
}

static	void			valid_forlight(t_node *n, int type)
{
	if (type == 0)
		n->lit.position = true;
	else if (type == 7)
		n->lit.intensity = true;
	else if (type == 1)
		n->lit.color = true;
}

static	void			valid_cmp(t_node *n, int type)
{
	if (n->type == 4)
		valid_forcam(n, type);
	else if (n->type == 5)
		valid_forlight(n, type);
	else
	{
		if (type == 0)
			n->cmp.position = true;
		else if (type == 1)
			n->cmp.color = true;
		else if (type == 2)
			n->cmp.radius = true;
		else if (type == 3)
			n->cmp.orientation = true;
	}
}

static	int				all_cmp_valid(t_node n)
{
	if (n.type == 4)
	{
		if ((n.cam.fov == false || n.cam.look_at == false ||
					n.cam.origin == false))
			return (-1);
	}
	else if (n.type == 5)
	{
		if ((n.lit.color == false || n.lit.intensity == false
					|| n.lit.position == false))
			return (-1);
	}
	else if (n.cmp.color == false ||
			n.cmp.orientation == false || n.cmp.radius == false ||
			n.cmp.position == false)
		return (-1);
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
		return (-1);
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
