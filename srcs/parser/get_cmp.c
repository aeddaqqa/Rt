/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:56:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:12:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				len_tab_2d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void			free_tab2(char ***tab, int l)
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

int				stock_rpa(double *dst, char *str, int type)
{
	*dst = ft_atod(str);
	if (type == ANGLE || type == FOV)
		*dst *= (M_PI / 180.0);
	else if (type == INTENSITY)
	{
		if (*dst < 0)
			*dst = 0;
		else if (*dst > 100)
			*dst = 100;
		*dst /= 100.0;
	}
	return (1);
}

int				rgb_to_int(t_color v)
{
	return ((((int)v.x & 0xff) << 16) |\
			(((int)v.y & 0xff) << 8) | ((int)v.z & 0xff));
}
