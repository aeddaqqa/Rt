/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:16:30 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/29 22:45:08 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst >= src)
	{
		while (len)
		{
			destination[len - 1] = source[len - 1];
			len--;
		}
		return (dst);
	}
	else
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	return (dst);
}
