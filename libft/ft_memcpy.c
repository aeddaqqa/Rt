/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:15:38 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/19 20:40:48 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char*)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		t[i] = *(unsigned char *)src;
		i++;
		src++;
	}
	return (dst);
}
