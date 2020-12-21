/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:07:26 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/20 14:03:40 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		t[i] = *(unsigned char *)src;
		if (t[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
		src++;
	}
	return (0);
}
