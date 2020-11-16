/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:40:34 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/11 16:56:47 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (s)
	{
		i = 0;
		if (fresh == NULL)
		{
			return (NULL);
		}
		while (i < len && s[start])
		{
			fresh[i] = s[start];
			i++;
			start++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
