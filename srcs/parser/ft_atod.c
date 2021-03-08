/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:10:27 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:12:55 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

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
