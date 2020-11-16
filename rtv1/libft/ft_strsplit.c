/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:08:00 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/23 01:46:34 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordscount(char const *s, char c)
{
	size_t words;
	size_t i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				i++;
				words++;
			}
		if (s[i])
			i++;
	}
	return (words);
}

static size_t	wordlen(char const *s, size_t i, char c)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	chars;
	char	**fresh;

	i = 0;
	if (!(s && (fresh = malloc((wordscount(s, c) + 1) * sizeof(char *)))))
		return (0);
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if (!(fresh[word] = malloc((wordlen(s, i, c) + 1) * sizeof(char))))
				return (0);
			chars = 0;
			while (s[i] != c && s[i])
				fresh[word][chars++] = s[i++];
			fresh[word++][chars] = '\0';
		}
	}
	fresh[word] = 0;
	return (fresh);
}
