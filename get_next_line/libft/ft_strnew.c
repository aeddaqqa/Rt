/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:38:32 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/08 20:21:51 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char*)malloc(sizeof(*fresh) * size + 1);
	if (fresh == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		fresh[i] = 0;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
