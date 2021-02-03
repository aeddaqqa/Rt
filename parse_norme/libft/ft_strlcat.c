/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 20:11:21 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/19 14:03:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sclen;
	size_t	dtlen;

	sclen = ft_strlen(src);
	dtlen = ft_strlen(dst);
	j = 0;
	i = dtlen;
	while (src[j] && i < (size - 1) && size != 0)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	if (size < dtlen)
		return (size + sclen);
	return (dtlen + sclen);
}
