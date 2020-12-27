/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:56:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 13:18:07 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		free_tab2(char ***tab, int l)
{
	int		i;
	char	**t;

	t = *tab;
	i = 0;
	while (i < l)
	{
		free(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

int				get_point(char *s, t_point *p)
{
	double		tab[3];
	int			i;
	char		**tmp;

	i = 0;
	tmp = ft_strsplit(s, ',');
	while (tmp[i])
	{
		if (i < 3)
			tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if (i != 3)
	{
		free_tab2(&tmp, i);
		return (-1);
	}
	free_tab2(&tmp, i);
	*p = (t_point){tab[0], tab[1], tab[2]};
	return (1);
}

int				get_ori_vect(char *s, t_vect3 *ori)
{
	char		**tmp;
	double		tab[3];
	int			i;

	i = 0;
	tmp = ft_strsplit(s, ',');
	while (tmp[i])
	{
		if (i < 3)
			tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if (i != 3)
	{
		free_tab2(&tmp, i);
		return (-1);
	}
	free_tab2(&tmp, i);
	*ori = (t_vect3){tab[0], tab[1], tab[2]};
	return (1);
}

int				get_color(char *s, t_color *color)
{
	int		r;
	int		g;
	int		b;
	int		c;

	c = ft_atoi(s);
	r = (c >> 16) & 255;
	g = (c >> 8) & 255;
	b = c & 255;
	color->x = r;
	color->y = g;
	color->z = b;
	return (1);
}

int				get_raduis_a(char *s, int type, double *r_a)
{
	double r;

	r = ft_atoi(s);
	if (type == 3)
		*r_a = M_PI * r / 180;
	else
		*r_a = r;
	return (1);
}
