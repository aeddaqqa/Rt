/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:40:34 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/19 20:04:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	s = 0;
	i = 0;
	s = (char *)malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (0);
	while (i <= size)
		s[i++] = '\0';
	return (s);
}
