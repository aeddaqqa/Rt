/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:01:01 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/14 15:04:06 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*find;

	i = 0;
	j = 0;
	find = (char *)needle;
	if (!(*find))
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == find[j] && find[j])
			j++;
		if (!find[j])
			return ((char*)haystack + i);
		i++;
	}
	return (0);
}
