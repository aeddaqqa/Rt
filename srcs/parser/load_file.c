/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:24:04 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/09 09:17:28 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

char		*read_file(char *path)
{
	char	*line;
	int		fd;
	char	*str;
	char	*tmp;
	DIR		*dirent;

	fd = open(path, O_RDONLY);
	dirent = NULL;
	if (fd < 0 || (dirent = opendir(path)))
	{
		if (dirent)
			closedir(dirent);
		return (NULL);
	}
	str = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	return (str);
}

char		*load_file(char *path)
{
	char	*tmp;
	char	*file;

	tmp = read_file(path);
	file = ft_strtrim(tmp);
	if (tmp)
		free(tmp);
	if (!file)
	{
		destroy(OPEN_FILE);
		return (NULL);
	}
	if (!*file)
	{
		free(file);
		destroy(EMPTY_FILE);
		return (NULL);
	}
	return (file);
}
