/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:21:43 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/24 12:34:41 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int			cmp_with_objects(char *s, char **tab)
{
	int	i;

	i = 0;
	if (s)
		while (i < LIMIT_ELEMENTS + 1)
		{
			if (!ft_strcmp(s, tab[i]))
				return (i);
			i++;
		}
	return (-1);
}

int		stock_ambient(char *str, t_tags tags, t_rt *rt)
{
	char	*inner;
	char	*tag;
	int 	j;
	
	j = 0;
	inner = inner_text(str, &j);
	rt->ambient = ft_atoi(inner);
	free(inner);
	tag = get_tag(str + j, &j);
	if (ft_strcmp(tag, tags.elements_c[AMBIENT]))
	{
		free(tag);
		return (-1);
	}
	free(tag);
	return (j);
}

int					stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
{
	t_node		node;
	char		*elem;
	int			r;
	void		*obj;

	*i = 0;
	node = init_node();
	obj = NULL;
	if ((white_space(&str[*i], i)) < 0)
		return (0);
	if (!(elem = get_tag(&str[*i], i)))
		return (0);
	if (!ft_strcmp("</scene>", elem))
	{
		ft_strdel(&elem);
		if (str[*i] || !rt->cameras || !rt->lights)
			return (0);
		return (1);
	}
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (0);
	}
	ft_strdel(&elem);
	if (node.type == AMBIENT)
	{
		if ((r = stock_ambient(str + *i, tags, rt)) == -1 || rt->ambient_exist)
			return (0);
		rt->ambient_exist = true;
		*i += r;
	}
	else
	{
		
		obj = new_object(node.type);/*protect*/
		if ((stock_elements_cmp(str, tags, node, i, obj)) < 0)
		{
			free(obj);
			return (0);
		}
		add_front(&rt, obj, node.type);
	}
	return (stock_elements(&str[*i], tags, i, rt));
}
