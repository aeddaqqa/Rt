/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_vect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:46:07 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:47:34 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	split_to_stock_vect3(char **split, int *i, double d[3])
{
	while (split[*i])
	{
		if (*i > 2)
		{
			free_tab2(&split, len_tab_2d(split));
			return (-1);
		}
		d[*i] = ft_atod(split[*i]);
		(*i)++;
	}
	return (1);
}

int			stock_vect3(t_vect3 *r, char *str, int type)
{
	int		i;
	double	d[3];
	char	**split;

	i = 0;
	if (!(split = ft_strsplit(str, ' ')))
	{
		free_tab2(&split, len_tab_2d(split));
		return (-1);
	}
	if (-1 == split_to_stock_vect3(split, &i, d))
		return (-1);
	free_tab2(&split, len_tab_2d(split));
	if (i != 3)
		return (-1);
	if (type == ORIENTATION)
		*r = normalize((t_vect3){d[0], d[1], d[2]});
	else
		*r = (t_vect3){d[0], d[1], d[2]};
	return (1);
}
