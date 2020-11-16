/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:49:32 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/06 19:41:03 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(unsigned long nbr, char *str, size_t count)
{
	str[count] = (nbr % 10) + 48;
	if (nbr >= 10)
	{
		count--;
		ft_cpy(nbr / 10, str, count);
	}
}

char		*ft_itoa(int n)
{
	size_t			count;
	unsigned long	nbr;
	char			*str;
	unsigned long	nb;

	count = 0;
	nbr = n;
	if (n <= 0)
	{
		nbr *= -1;
		count++;
	}
	nb = nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	ft_cpy(nb, str, count - 1);
	if (n < 0)
		str[0] = '-';
	str[count] = '\0';
	return (str);
}
