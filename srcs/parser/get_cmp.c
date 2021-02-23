/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:56:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 17:27:55 by nabouzah         ###   ########.fr       */
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

int				stock_rpa(double *dst, char *str)
{
	*dst = ft_atoi(str);
	return (1);
}

int				rgb_to_int(t_color v)
{
	return ((((int)v.x & 0xff) << 16) |\
			(((int)v.y & 0xff) << 8) | ((int)v.z & 0xff));
}
