/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:11:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/05 08:09:45 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_object *stock_points(int nb, char *path)
{
	t_point tab[nb];
	t_object *obj;
	t_object *tmp;
	char **split;
	char *line;
	int indice;
	int fd;
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	obj = NULL;
	tmp = NULL;
	split = NULL;
	fd = open(path, O_RDONLY);
	indice = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		// if (*line && (*line == 's' || *line == '#' || *line == 'm' || *line == 'g' || *line == 'o'))
		// 	continue;
		if (!split)
			return (NULL);
		if (!*split)
			continue;
		if (z < nb && !ft_strcmp(split[0], "v"))
		{
			j = 0;
			while (split[j])
				j++;
			if (j == 4)
			{
				tab[z] = (t_point){ft_atod(split[1]), ft_atod(split[2]), ft_atod(split[3])};
				z++;
			}
			free_tab2(&split, j);
		}
		else if (!(ft_strcmp(split[0], "f")))
		{
			j = 0;
			while (split[j])
			{
				indice = ft_atoi(split[j]);
				if (j != 0)
					if (indice > nb || indice < 0)
						return (NULL);
				j++;
			}
			if (j != 4)
				return (NULL);
			if (!obj)
			{
				obj = (t_object *)new_object(TRIANGLE);
				obj->type = TRIANGLE;
				obj->point_a = tab[ft_atoi(split[1]) - 1];
				obj->point_b = tab[ft_atoi(split[2]) - 1];
				obj->point_c = tab[ft_atoi(split[3]) - 1];
				obj->color = (t_color){1.0, 1.0, 1.0};
				tmp = obj;
			}
			else
			{
				tmp->next = (t_object *)new_object(TRIANGLE);
				tmp->next->type = TRIANGLE;
				tmp->next->point_a = tab[ft_atoi(split[1]) - 1];
				tmp->next->point_b = tab[ft_atoi(split[2]) - 1];
				tmp->next->point_c = tab[ft_atoi(split[3]) - 1];
				tmp->next->color = (t_color){1.0, 1.0, 1.0};
				tmp = tmp->next;
				free_tab2(&split, j);
			}
		}
	}
	return (obj);
}

t_object *load_fileobj(char *path)
{
	char *line;
	int fd;
	int nb;

	nb = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#' || *line == 'o' || *line == 'g' || *line == 'm'))
			continue;
		else if (*line == 'v' && *(line + 1) && *(line + 1) != 't' && *(line + 1) != 'n')
			nb++;
	}
	close(fd);
	if (!nb)
		return (NULL);
	return (stock_points(nb, path));
}

int parse_obj(t_rt *rt, char *path)
{
	if (!(rt->objects = load_fileobj(path)))
		return (0);
	rt->cameras = new_object(CAMERA);
	rt->cameras->o = (t_vect3){-1.0, 0, 2.0};
	rt->cameras->l = (t_vect3){0, 0, 0};
	rt->cameras->up = (t_vect3){0, 1, 0};
	rt->cameras->fov = stock_rpa(&rt->cameras->fov, "60", CAMERA);
	rt->ambient = 0.1;
	rt->lights = new_object(LIGHT);
	rt->lights->color = (t_vect3){1, 1, 1};
	rt->lights->position = (t_vect3){0, 0, 1.5};
	rt->lights->intensity = 100;
	return (1);
}