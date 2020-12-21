/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:27:08 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/19 14:53:04 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	fresh = 0;
	i = 0;
	if (!s)
		return (0);
	if (!(fresh = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (len > 0)
	{
		while (i < len)
		{
			fresh[i] = s[start];
			start++;
			i++;
		}
	}
	fresh[i] = '\0';
	return (fresh);
}
