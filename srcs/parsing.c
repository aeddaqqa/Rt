/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:35:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/09 05:29:29 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	which_object(t_rt *rt, int fd, char *key)
{
	if (!(ft_strcmp("plane", key)))
		parse_objects(rt, fd, PLANE);
	else if (!(ft_strcmp("sphere", key)))
		parse_objects(rt, fd, SPHERE);
	else if (!(ft_strcmp("cylinder", key)))
		parse_objects(rt, fd, CYLINDER);
	else if (!(ft_strcmp("cone", key)))
		parse_objects(rt, fd, CONE);
}

int			check_argument(t_rt *rt, t_obj *obj, char ***s)
{
	char	**data;
	char	*shape[4];

	data = *s;
	shape[0] = "PLANE";
	shape[1] = "SPHERE";
	shape[2] = "CYLINDER";
	shape[3] = "CONE";
	if (data && data[0] && !is_object(data[0]) && (!data[1] || !data[1][0]))
	{
		ft_putstr("OBJECT: ");
		ft_putendl(shape[obj->type]);
		ft_putstr("ARGUMENT: ");
		ft_putendl(data[0]);
		ft_putendl("HAS NO VALUE");
		ft_strdel(&data[0]);
		free_double_ptr(s);
		destroy(rt, OBJECT_PROPERTY);
	}
	return (0);
}

void		stock(t_rt *rt, int fd)
{
	char	*line;
	char	*key;
	int		rd;
	int		step;

	step = 0;
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		++step;
		if (line && (key = ft_strtrim(line)))
		{
			if (!ft_strcmp(key, "light"))
				new_light(rt, fd);
			else if (!ft_strcmp(key, "camera"))
				new_camera(rt, fd);
			if (is_object(key))
				which_object(rt, fd, key);
			ft_strdel(&key);
		}
		ft_strdel(&line);
	}
	if (step == 0 && rd <= 0)
		destroy(rt, rd < 0 ? READ_FILE : EMPTY_FILE);
}
