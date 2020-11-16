/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:08:08 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/14 13:53:39 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		s_size;
	int		i;

	i = 0;
	s_size = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * (s_size + 1));
	if (str == NULL)
		return (0);
	while (i < s_size)
	{
		str[i] = s1[i];
		i++;
	}
	str[s_size] = '\0';
	return (str);
}
