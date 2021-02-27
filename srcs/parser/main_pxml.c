/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pxml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:10:36 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/27 18:31:00 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int		open_scene(char *str)
{
	int		i;
	char	*elem;

	i = 0;
	if (str[0] != '<')
		return (-1);
	i = 0;
	while (str[i] && str[i] != '>')
		i++;
	if (!str[i])
		return (-1);
	elem = ft_strsub(str, 0, i + 1);
	if (ft_strcmp(elem, "<scene>"))
	{
		free(elem);
		return (-1);
	}
	free(elem);
	return (i);
}

int				parse(char *file, t_rt *rt)
{
	int		z;
	int		y;
	t_tags	tags;

	if ((z = open_scene(file)) < 0)
	{
		destroy(SCENE_NOT_FOUND);
		return (0);
	}
	else
	{
		tags = init_tab_tags();
		y = 0;
		if (!(stock_elements(file + z + 1, tags, &y, rt)))
			return (0);
	}
	return (1);
}
