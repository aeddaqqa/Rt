/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:12:36 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/12 16:27:23 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		n;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2) + 1;
		fresh = (char *)malloc(sizeof(char) * n);
		if (fresh == NULL)
		{
			return (NULL);
		}
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
		return (fresh);
	}
	return (NULL);
}
