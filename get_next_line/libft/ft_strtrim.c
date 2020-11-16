/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:30:32 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/14 17:54:29 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*fresh;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' ||
				s[i] == '\t') && s[i] != '\0')
		i++;
	j = ft_strlen(s);
	while (((s[j - 1] == ' ') || (s[j - 1] == '\n') ||
				(s[j - 1] == '\t')) && (s[i] != '\0'))
		j--;
	fresh = ft_strsub(s, i, j - i);
	if (fresh)
		return (fresh);
	return (NULL);
}
