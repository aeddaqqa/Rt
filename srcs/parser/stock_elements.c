/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:21:43 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/24 09:49:13 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			cmp_with_objects(char *s, char **tab)
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

int			stock_ambient(char *str, t_tags tags, t_rt *rt)
{
	char	*inner;
	char	*tag;
	int		j;

	j = 0;
	inner = inner_text(str, &j);
	rt->ambient = ft_atoi(inner);
	if (rt->ambient < 0)
		rt->ambient = 0;
	else if (rt->ambient > 100)
		rt->ambient = 100;
	rt->ambient /= 100.0;
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

int			end_scene(char *str, int i, char **el, t_rt *rt)
{
	char *elem;

	elem = *el;
	ft_strdel(&elem);
	if (str[i] || !rt->cameras || !rt->lights ||\
			rt->ambient_exist == false)
		return (0);
	return (1);
}

int			stock_elem_amb(char *str, int *i, t_tags tags, t_rt *rt)
{
	int			r;

	if (rt->node.type == AMBIENT)
	{
		if ((r = stock_ambient(str + *i, tags, rt)) == -1 || rt->ambient_exist)
			return (0);
		rt->ambient_exist = true;
		*i += r;
	}
	else
	{
		rt->obj = new_object(rt->node.type);
		if (rt->node.type == LIGHT)
			rt->nbr_lights++;
		else if (rt->node.type != CAMERA)
			rt->obj->type = rt->node.type;
		if ((stock_elements_cmp(str, tags, rt, i)) < 0)
		{
			free(rt->obj);
			return (0);
		}
		add_front(&rt, rt->obj, rt->node.type);
	}
	return (1);
}

int			stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
{
	char		*elem;

	*i = 0;
	rt->node = init_node();
	if (((white_space(&str[*i], i)) < 0) || !(elem = get_tag(&str[*i], i)))
		return (0);
	if (!ft_strcmp("</scene>", elem))
		return (end_scene(str, *i, &elem, rt));
	if ((rt->node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (0);
	}
	ft_strdel(&elem);
	if (!stock_elem_amb(str, i, tags, rt))
		return (0);
	return (stock_elements(&str[*i], tags, i, rt));
}
