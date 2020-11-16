/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:17:59 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/13 13:53:32 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sto;

	if ((sto = (char *)malloc(len)))
	{
		sto = ft_memcpy(sto, src, len);
		dst = ft_memcpy(dst, sto, len);
	}
	free(sto);
	return (dst);
}
