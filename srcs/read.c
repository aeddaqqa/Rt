/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 08:37:34 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:31:15 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	in_base(char c)
{
	char	*lo_base;
	char	*up_base;
	int		i;

	i = 0;
	lo_base = "0123456789abcdef";
	up_base = "0123456789ABCDEF";
	if (c >= 'A' && c <= 'F')
		while (up_base[i] && up_base[i] != c)
			i++;
	else if (c >= 'a' && c <= 'f')
		while (lo_base[i] && lo_base[i] != c)
			i++;
	else if (c >= '0' && c <= '9')
		while (lo_base[i] && lo_base[i] != c)
			i++;
	else
		i = -1;
	return (i);
}

t_color		read_color(char **v)
{
	int		color;
	int		i;
	int		hex;
	char	*data;
	int		digit;

	data = *v;
	color = 0;
	if (!ft_isdigit(data[0]))
		return (to_rgb(color));
	hex = is_hex(data);
	i = hex ? 1 : -1;
	while (data && data[++i])
	{
		if ((digit = in_base(data[i])) < 0)
		{
			ft_strdel(v);
			return ((t_color){0, 0, 0});
		}
		color = color * (hex ? 16 : 10) + digit;
	}
	ft_strdel(v);
	return (to_rgb(color));
}

char		**value(t_rt *rt, int fd)
{
	char	*line;
	char	**s;
	char	*tmp;

	get_next_line(fd, &line);
	if (!line || !*line)
		return (NULL);
	if (!(s = ft_strsplit(line, ':')))
	{
		ft_strdel(&line);
		destroy(rt, MALLOC_ERROR);
	}
	tmp = s[0];
	s[0] = ft_strtrim(s[0]);
	ft_strdel(&tmp);
	tmp = s[1];
	s[1] = ft_strtrim(s[1]);
	ft_strdel(&tmp);
	return (s);
}

t_vector	read_vector(char **value)
{
	double	c[3];
	char	**vec;
	int		i;
	int		k;

	i = -1;
	k = -1;
	vec = ft_strsplit(*value, ' ');
	ft_strdel(value);
	while (vec && vec[++i])
	{
		++k < 3 ? c[k] = ft_atoi(vec[i]) : 0;
		ft_strdel(&vec[i]);
	}
	free(vec);
	return ((t_vector){c[0], c[1], c[2]});
}

double		read_scalar(char **value)
{
	double	new;

	if (!*value)
		return (0);
	new = ft_atoi(*value) + 0.001;
	ft_strdel(value);
	return (new < 0 ? 0 : new);
}
