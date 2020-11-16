/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:49:14 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/16 15:10:18 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	int		length;
	char	*fresh;

	size = 1;
	sign = 0;
	length = n;
	if (n < 0)
		sign = 1;
	while ((length = length / 10))
		size++;
	fresh = ft_strnew(size + sign);
	if (fresh == NULL)
		return (NULL);
	if (sign == 1)
		fresh[0] = '-';
	while (size--)
	{
		fresh[size + sign] = (sign == 1 ? -(n % 10) : (n % 10)) + 48;
		n = n / 10;
	}
	return (fresh);
}
