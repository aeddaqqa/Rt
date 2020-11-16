/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:39:48 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/14 14:23:34 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*str;

	i = 0;
	a = (char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == a)
			return (str + i);
		i++;
	}
	if (str[i] == a)
		return (str + i);
	return (NULL);
}
