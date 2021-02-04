/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:39:10 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/23 15:42:31 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	a;
	long int	b;

	b = 1;
	a = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			b = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		a = a * 10 + *str - '0';
		str++;
	}
	a = a * b;
	return (a);
}
