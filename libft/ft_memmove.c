/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:44:57 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/20 01:50:10 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sr;

	if (!(sr = (unsigned char *)malloc(len * sizeof(unsigned char))) ||\
			!(dst || src))
		return (0);
	ft_memcpy(sr, src, len);
	ft_memcpy(dst, sr, len);
	ft_strdel((char **)&sr);
	return (dst);
}
