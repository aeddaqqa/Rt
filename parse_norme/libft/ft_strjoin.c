/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:12:16 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/18 00:50:09 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	if (!(fresh = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *\
					sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		fresh[i + j] = s2[j];
		j++;
	}
	fresh[i + j] = '\0';
	return (fresh);
}
