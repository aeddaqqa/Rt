/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:09:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/06 17:57:25 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_sum(const char *s1, const char *s2)
{
	int s1_len;
	int s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		return (s1_len + s2_len);
	}
	return (0);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (s1 && s2)
	{
		new = (char *)malloc(sizeof(char) * ft_len_sum(s1, s2) + 1);
		if (new == NULL)
			return (0);
		i = -1;
		while (s1[++i])
			new[i] = s1[i];
		j = 0;
		while (s2[j])
		{
			new[i] = s2[j];
			i++;
			j++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
