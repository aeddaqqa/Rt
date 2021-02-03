/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:52:02 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/15 00:17:53 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	i = 0;
	while (sr1[i] || sr2[i])
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
	}
	return (0);
}
