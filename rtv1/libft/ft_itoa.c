/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:36:22 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/19 15:10:07 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_devide(size_t n)
{
	size_t		i;

	i = 1;
	if (n == 0)
		return (i);
	while (n > 0)
	{
		n = n / 10;
		i = i * 10;
	}
	i = i / 10;
	return (i);
}

static size_t	ft_nbrlen(int nbr)
{
	size_t	i;
	size_t	nb;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nb = -1 * (size_t)nbr;
	}
	else
		nb = (size_t)nbr;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*fresh;
	int			j;
	int			i;
	size_t		nb;

	i = 0;
	if (!(fresh = (char *)malloc((ft_nbrlen(n) + 1) * sizeof(char))))
		return (0);
	if (n < 0)
	{
		nb = -1 * (size_t)n;
		fresh[0] = '-';
		i = 1;
	}
	else
		nb = (size_t)n;
	j = ft_devide(nb);
	while (j > 0)
	{
		fresh[i++] = nb / j + '0';
		nb = nb % j;
		j = j / 10;
	}
	fresh[i] = '\0';
	return (fresh);
}
