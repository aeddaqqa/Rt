/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:37:37 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/23 13:42:29 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_true_num(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_cor(char *str)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_words_counter(str, ',') != 3)
		return (0);
	tab = ft_strsplit(str, ',');
	if (!ft_true_num(tab[0]))
		i = 0;
	if (!ft_true_num(tab[1]))
		i = 0;
	if (!ft_true_num(tab[2]))
		i = 0;
	if (!((ft_atoi(tab[0]) <= 2000) && (ft_atoi(tab[0]) >= -2000)))
		i = 0;
	if (!((ft_atoi(tab[1]) <= 2000) && (ft_atoi(tab[1]) >= -2000)))
		i = 0;
	if (!((ft_atoi(tab[2]) <= 2000) && (ft_atoi(tab[2]) >= -2000)))
		i = 0;
	ft_2dfree(tab);
	return (i);
}

int	ft_clr(char *str)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_words_counter(str, ',') != 3)
		return (0);
	tab = ft_strsplit(str, ',');
	if (!ft_true_num(tab[0]))
		i = 0;
	if (!ft_true_num(tab[1]))
		i = 0;
	if (!ft_true_num(tab[2]))
		i = 0;
	if (!((ft_atoi(tab[0]) <= 255) && (ft_atoi(tab[0]) >= 0)))
		i = 0;
	if (!((ft_atoi(tab[1]) <= 255) && (ft_atoi(tab[1]) >= 0)))
		i = 0;
	if (!((ft_atoi(tab[2]) <= 255) && (ft_atoi(tab[2]) >= 0)))
		i = 0;
	ft_2dfree(tab);
	return (i);
}

int	ft_num(char *str)
{
	if (!ft_true_num(str))
		return (0);
	if (ft_atoi(str) < 0 || ft_atoi(str) > 2000)
		return (0);
	return (1);
}

int	ft_cornor(char *str)
{
	t_err	z;
	char	**tab;

	z = (t_err){0, 0, 1};
	if (ft_words_counter(str, ',') != 3)
		return (0);
	tab = ft_strsplit(str, ',');
	if (!ft_true_num(tab[0]) || !ft_true_num(tab[1]) || !ft_true_num(tab[2]))
		z.i = 0;
	if (ft_atoi(tab[0]) != -1 && ft_atoi(tab[0]) != 0 && ft_atoi(tab[0]) != 1)
		z.err++;
	if (ft_atoi(tab[1]) != -1 && ft_atoi(tab[1]) != 0 && ft_atoi(tab[1]) != 1)
		z.err++;
	if (ft_atoi(tab[2]) != -1 && ft_atoi(tab[2]) != 0 && ft_atoi(tab[2]) != 1)
		z.err++;
	if (ft_atoi(tab[0]) == -1 || ft_atoi(tab[0]) == 1)
		z.ch++;
	if (ft_atoi(tab[1]) == -1 || ft_atoi(tab[1]) == 1)
		z.ch++;
	if (ft_atoi(tab[2]) == -1 || ft_atoi(tab[2]) == 1)
		z.ch++;
	ft_2dfree(tab);
	if (z.err != 0 || z.ch != 1 || z.i == 0)
		return (0);
	return (1);
}
