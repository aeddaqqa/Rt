/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:31:26 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/10/24 09:12:37 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cond(char *s, char **line)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	*line = ft_strsub(s, 0, i);
	if (!s[i])
		s = ft_strdup(s + i);
	else
		s = ft_strdup(s + i + 1);
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	char		tab[BUFF_SIZE + 1];
	static char	*p[4864];
	char		*t;
	int			j;

	if (read(fd, tab, 0) < 0 || line == NULL)
		return (-1);
	if (!p[fd])
		p[fd] = ft_strnew(0);
	while ((j = read(fd, tab, BUFF_SIZE)) > 0)
	{
		tab[j] = '\0';
		t = ft_strjoin(p[fd], tab);
		free(p[fd]);
		p[fd] = t;
		if (ft_strchr(p[fd], '\n') != NULL)
			break ;
	}
	if (j == 0 && !(ft_strlen(p[fd])))
		return (0);
	t = cond(p[fd], line);
	free(p[fd]);
	p[fd] = t;
	return (1);
}
