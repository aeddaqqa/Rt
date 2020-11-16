/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:24:18 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/07 18:50:42 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	const char		*s2;
	unsigned char	b;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (char *)src;
	b = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == b)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
