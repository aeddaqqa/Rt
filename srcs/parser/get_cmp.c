/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:56:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/24 11:10:33 by aeddaqqa         ###   ########.fr       */
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

static double	to_double(const char *str, int i, int signe, double resultat)
{
	double sub;
	double dix;
	double div;

	dix = 10;
	div = 0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sub = str[i] - '0';
		div = div + sub / dix;
		dix *= 10;
		i++;
	}
	return ((div + resultat) * signe);
}

double			ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' ||\
			str[i] == '\n' || str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		return (to_double(str, i, sign, result));
	else
		return (result * sign);
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
