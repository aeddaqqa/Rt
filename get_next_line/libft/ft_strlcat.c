/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:38:22 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/04 15:59:53 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int res;
	int f;

	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	if ((int)size <= i)
		res = j + size;
	else
		res = j + i;
	f = 0;
	while (src[f] && i + 1 < (int)size)
	{
		dst[i] = src[f];
		i++;
		f++;
	}
	dst[i] = '\0';
	return (res);
}
