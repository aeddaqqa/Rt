/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:22:00 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/11 17:03:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t		i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while ((s1[i] || s2[i]) && i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
