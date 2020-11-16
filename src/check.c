/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:37:25 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/23 11:33:44 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check1(char *line)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_words_counter(line, '\t') != 4)
		return (0);
	tab = ft_strsplit(line, '\t');
	if (!ft_cor(tab[1]) || !ft_cor(tab[2]) || !ft_cor(tab[3]))
		i = 0;
	ft_2dfree(tab);
	return (i);
}

int	ft_check2(char *line)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_strncmp(line, "lit\t", 4) == 0 && ft_words_counter(line, '\t') != 5)
		return (0);
	else if (ft_strncmp(line, "sph\t", 4) == 0 && \
			ft_words_counter(line, '\t') != 6)
		return (0);
	tab = ft_strsplit(line, '\t');
	if (!ft_cor(tab[1]) || !ft_cor(tab[2]) || !ft_clr(tab[3]))
		i = 0;
	if (ft_strncmp(line, "lit\t", 4) == 0 && !(ft_num(tab[4])))
		i = 0;
	if (ft_strncmp(line, "sph\t", 4) == 0 && !(ft_cor(tab[4])))
		i = 0;
	if (ft_strncmp(line, "sph\t", 4) == 0 && !(ft_num(tab[5])))
		i = 0;
	ft_2dfree(tab);
	return (i);
}

int	ft_check3(char *line)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_strncmp(line, "con\t", 4) == 0 && ft_words_counter(line, '\t') == 7)
	{
		tab = ft_strsplit(line, '\t');
		if (!ft_clr(tab[3]) || !ft_cornor(tab[5]) || !ft_num(tab[6]) \
				|| !ft_cor(tab[1]) || !ft_cor(tab[2]) || !ft_cor(tab[4]))
			i = 0;
		ft_2dfree(tab);
	}
	else if (ft_strncmp(line, "cyl\t", 4) == 0 && \
			ft_words_counter(line, '\t') == 7)
	{
		tab = ft_strsplit(line, '\t');
		if (!ft_cor(tab[1]) || !ft_cor(tab[2]) || !ft_cor(tab[4]))
			i = 0;
		if (!ft_clr(tab[3]) || !ft_num(tab[5]) || !ft_cornor(tab[6]))
			i = 0;
		ft_2dfree(tab);
	}
	else
		i = 0;
	return (i);
}

int	ft_check4(char *line)
{
	char	**tab;
	int		i;

	i = 1;
	if (ft_words_counter(line, '\t') != 6)
		return (0);
	tab = ft_strsplit(line, '\t');
	if (!ft_cor(tab[1]) || !ft_cor(tab[2]) || !ft_cor(tab[4]))
		i = 0;
	if (!ft_clr(tab[3]) || !ft_cornor(tab[5]))
		i = 0;
	ft_2dfree(tab);
	return (i);
}

int	ft_check(char *line)
{
	if (ft_strncmp(line, "cam\t", 4) == 0)
		return (ft_check1(line));
	else if (ft_strncmp(line, "lit\t", 4) == 0)
		return (ft_check2(line));
	else if (ft_strncmp(line, "sph\t", 4) == 0)
		return (ft_check2(line));
	else if (ft_strncmp(line, "cyl\t", 4) == 0)
		return (ft_check3(line));
	else if (ft_strncmp(line, "con\t", 4) == 0)
		return (ft_check3(line));
	else if (ft_strncmp(line, "pla\t", 4) == 0)
		return (ft_check4(line));
	return (0);
}
