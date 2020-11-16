/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:19:32 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/14 14:32:45 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*str;

	i = ft_strlen(s);
	a = (char)c;
	str = (char *)s;
	while (i)
	{
		if (str[i] == a)
			return (str + i);
		i--;
	}
	if (str[0] == a)
		return (str + i);
	return (NULL);
}
