/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:21:43 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 13:19:01 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int			cmp_with_objects(char *s, char **tab)
{
	int	i;

	i = 0;
	if (s)
		while (i < 6)
		{
			if (!ft_strcmp(s, tab[i]))
				return (i);
			i++;
		}
	return (-1);
}

int					stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
{
	t_node		node;
	char		*elem;
	void		*obj;

	*i = 0;
	node = init_node();
	if ((white_space(&str[*i], i)) < 0)
		return (0);
	if (!(elem = get_tag(&str[*i], i)))
		return (0);
	if (!ft_strcmp("</scene>", elem))
	{
		ft_strdel(&elem);
		if (str[*i])
			return (0);
		return (1);
	}
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (0);
	}
	ft_strdel(&elem);
	obj = new_object(node.type);
	if ((stock_elements_cmp(str, tags, node, i, obj)) < 0)
	{
		free(obj);
		return (0);
	}
	add_front(&rt, obj, node.type);
	return (stock_elements(&str[*i], tags, i, rt));
}
