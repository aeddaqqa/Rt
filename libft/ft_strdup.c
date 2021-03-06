/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:09:08 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/16 16:54:05 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*tab;
	size_t	srclen;

	srclen = ft_strlen(src);
	tab = (char *)malloc((srclen + 1) * sizeof(char));
	if (tab == 0)
		return (0);
	i = 0;
	while (i < srclen)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
