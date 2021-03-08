/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:11:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 17:58:08 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			str_v(t_stk *w, t_point *tab)
{
	int		j;

	j = 0;
	while (w->split[j])
		j++;
	if (j == 4)
	{
		tab[w->z] = (t_point){ft_atod(w->split[1]), ft_atod(w->split[2]), \
			ft_atod(w->split[3])};
		w->z++;
	}
	free_tab2(&w->split, j);
}

int				str_f(t_stk *w, int nb, t_point *tab)
{
	int		j;

	j = 0;
	while (w->split[j])
	{
		w->indice = ft_atoi(w->split[j]);
		if (j != 0)
			if (w->indice > nb || w->indice < 0)
				return (0);
		j++;
	}
	if (j != 4)
		return (0);
	test_obj(w, tab, j);
	return (1);
}

t_object		*stock_points(int nb, char *path)
{
	t_point tab[nb];
	char	*line;
	int		fd;
	t_stk	w;

	w = (t_stk){0, 0, 0, NULL, NULL, NULL};
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		w.split = ft_strsplit(line, ' ');
		if (!w.split)
			return (NULL);
		if (!*w.split)
			continue;
		if (w.z < nb && !ft_strcmp(w.split[0], "v"))
			str_v(&w, tab);
		else if (!(ft_strcmp(w.split[0], "f")))
		{
			if (str_f(&w, nb, tab) == 0)
				return (NULL);
		}
	}
	return (w.obj);
}

t_object		*load_fileobj(char *path)
{
	char	*line;
	int		fd;
	int		nb;

	nb = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#' || *line == 'o' || \
					*line == 'g' || *line == 'm'))
			continue;
		else if (*line == 'v' && *(line + 1) && *(line + 1) != 't' && \
				*(line + 1) != 'n')
			nb++;
	}
	close(fd);
	if (!nb)
		return (NULL);
	return (stock_points(nb, path));
}

int				parse_obj(t_rt *rt, char *path)
{
	if (!(rt->objects = load_fileobj(path)))
		return (0);
	rt->cameras = new_object(CAMERA);
	rt->cameras->o = (t_vect3){0, 0, 5.0};
	rt->cameras->l = (t_vect3){0, 0, 0};
	rt->cameras->up = (t_vect3){0, 1, 0};
	rt->cameras->fov = stock_rpa(&rt->cameras->fov, "60", CAMERA);
	rt->ambient = 0.05;
	rt->lights = new_object(LIGHT);
	rt->lights->color = (t_vect3){1, 1, 1};
	rt->lights->position = (t_vect3){0, 0, 10};
	rt->lights->intensity = 1;
	return (1);
}
