/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:33:04 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/07 17:47:46 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	string = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}
