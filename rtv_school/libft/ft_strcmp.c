/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:54:45 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/03/31 21:48:17 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	while (src[i] != '\0' || dst[i] != '\0')
	{
		if (src[i] != dst[i])
		{
			return (src[i] - dst[i]);
		}
		i++;
	}
	return (0);
}
