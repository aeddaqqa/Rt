/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 23:16:23 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/20 23:17:10 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sp_begin(char const *s)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			&& (s[i]))
	{
		count++;
		i++;
	}
	return (count);
}

static int	sp_end(char const *s)
{
	int		i;
	size_t	count;

	count = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		count++;
		i--;
	}
	return (count);
}

char		*ft_strtrim(char const *s)
{
	int		size;
	char	*fresh;
	int		i;
	int		j;

	fresh = 0;
	j = 0;
	if (!s)
		return (0);
	size = ft_strlen(s) - sp_begin(s) - sp_end(s);
	if (size > 0)
	{
		fresh = (char *)malloc((size + 1) * sizeof(char));
		if (fresh == 0)
			return (0);
		i = sp_begin(s);
		while (j < size && size != 0)
			fresh[j++] = s[i++];
	}
	else if (!(fresh = (char *)malloc(sizeof(char))))
		return (0);
	fresh[j] = '\0';
	return (fresh);
}
