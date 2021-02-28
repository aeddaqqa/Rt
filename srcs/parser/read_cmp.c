/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:58:17 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/28 08:40:36 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int stock_vect3(t_vect3 *r, char *str, int type)
{
	char **split;
	int i;
	double d[3];

	i = 0;
	if (!(split = ft_strsplit(str, ' ')))
	{
		free_tab2(&split, len_tab_2d(split));
		return (-1);
	}
	while (split[i])
	{
		if (i > 2)
		{
			free_tab2(&split, len_tab_2d(split));
			return (-1);
		}
		d[i] = ft_atod(split[i]);
		i++;
	}
	free_tab2(&split, len_tab_2d(split));
	if (i != 3)
		return (-1);
	if (type == ORIENTATION)
		*r = normalize((t_vect3){d[0], d[1], d[2]});
	else
		*r = (t_vect3){d[0], d[1], d[2]};
	return (1);
}

static int in_base(char c)
{
	char *lo_base;
	char *up_base;
	int i;

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

int is_hex(char *value)
{
	int len;

	len = ft_strlen(value);
	if (len > 2 && len <= 10 && value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
		return (1);
	return (0);
}

int to_rgb(t_color *co, int c)
{
	co->x = ((c >> 16) & 255) / 255.0;
	co->y = ((c >> 8) & 255) / 255.0;
	co->z = (c & 255) / 255.0;
	return (1);
}

int 	read_color(t_color *c, char *data)
{
	int color;
	int i;
	int hex;
	int digit;

	color = 0;
	if (!ft_isdigit(data[0]))
		return (to_rgb(c, color));
	hex = is_hex(data);
	i = hex ? 1 : -1;
	while (data && data[++i])
	{
		if ((digit = in_base(data[i])) < 0)
			return (0);
		color = color * (hex ? 16 : 10) + digit;
	}
	return (to_rgb(c, color));
}
