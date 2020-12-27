/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:54:16 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 13:17:49 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				check_openning_elem(char *s, char **tab)
{
	int		i;

	i = 0;
	while (i < 9)
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
	if (type != 6 && type != 5 && type != 7)
		return (-1);
	if (type == 6 && n.cam.origin == true)
		return (-1);
	else if (type == 5 && n.cam.look_at == true)
		return (-1);
	else if (type == 7 && n.cam.fov == true)
		return (-1);
	return (1);
}

static int		check_cmp_exist_forobj(t_node n, int type)
{
	if (type != 0 && type != 1 && type != 2 && type != 3 && type != 4)
		return (-1);
	if (type == 0 && n.cmp.position == true)
		return (-1);
	else if (type == 1 && n.cmp.color == true)
		return (-1);
	else if (type == 2 && n.cmp.radius == true)
		return (-1);
	else if (type == 3 && n.cmp.ambient == true)
		return (-1);
	else if (type == 4 && n.cmp.orientation == true)
		return (-1);
	return (1);
}

int				check_components_exist(t_node n, int type)
{
	if (n.type == 4)
		return (check_cmp_exist_forcam(n, type));
	else if (n.type == 5)
	{
		if (type != 0 && type != 8 && type != 1)
			return (-1);
		if (type == 0 && n.lit.position == true)
			return (-1);
		else if (type == 8 && n.lit.intensity == true)
			return (-1);
		else if (type == 1 && n.lit.color == true)
			return (-1);
	}
	else
		return (check_cmp_exist_forobj(n, type));
	return (1);
}
