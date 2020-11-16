/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:28:31 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/03/31 21:57:06 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t dstlen;

	i = 0;
	dstlen = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[dstlen] = s2[i];
		dstlen++;
		i++;
	}
	s1[dstlen] = '\0';
	return (s1);
}
