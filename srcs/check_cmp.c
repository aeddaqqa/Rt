/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:54:16 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/22 16:21:28 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				check_openning_elem(char *s, char **tab)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int				check_closing_elem(char *s, int n, char **tab, int *i)
{
	char	*tag;

	if (!(tag = get_tag(s, i)))
		return (-1);
	if (!ft_strcmp(tab[n], tag))
	{
		ft_strdel(&tag);
		return (1);
	}
	ft_strdel(&tag);
	return (-1);
}

static int		check_cmp_exist_forcam(t_node n, int type)
{
	if (type != ORIGIN && type != LOOK_AT && type != FOV)
		return (-1);
	if (type == ORIGIN && n.cam.origin == true)
		return (-1);
	else if (type == LOOK_AT && n.cam.look_at == true)
		return (-1);
	else if (type == FOV && n.cam.fov == true)
		return (-1);
	return (1);
}

int		check_for_sphere(int type, t_node n)
{
	if (type != POSITION && type != COLOR && type != RADIUS && type != ORIENTATION
		&& type != TRANSITION)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == RADIUS && n.cmp.radius == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == TRANSITION && n.cmp.transition == true)
		return (-1);
	return (1);
}

static int		check_cmp_exist_forobj(t_node n, int type)
{
	if (n.type == SPHERE)
		return(check_for_sphere(type, n));
	return (1);
}

int				check_components_exist(t_node n, int type)
{
	if (n.type == CAMERA)
		return (check_cmp_exist_forcam(n, type));
	else if (n.type == LIGHT)
	{
		if (type != POSITION && type != INTENSITY && type != COLOR)
			return (-1);
		if (type == POSITION && n.lit.position == true)
			return (-1);
		else if (type == INTENSITY && n.lit.intensity == true)
			return (-1);
		else if (type == COLOR && n.lit.color == true)
			return (-1);
	}
	else
		return (check_cmp_exist_forobj(n, type));
	return (1);
}
