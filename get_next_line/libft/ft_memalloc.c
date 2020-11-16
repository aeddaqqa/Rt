/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:11:21 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/08 13:09:23 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char*)malloc(sizeof(*fresh) * size);
	if (fresh == NULL)
	{
		return (NULL);
	}
	if (size > 0)
	{
		while (i < size)
		{
			fresh[i] = 0;
			i++;
		}
	}
	return (fresh);
}
