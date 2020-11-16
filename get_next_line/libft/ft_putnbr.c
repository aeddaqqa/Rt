/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:18:56 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/15 14:39:45 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = num * (-1);
	}
	if (num >= 0 && num <= 9)
	{
		ft_putchar(48 + num);
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putchar(48 + (num % 10));
	}
}
