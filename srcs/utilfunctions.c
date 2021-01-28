/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:39:07 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/28 17:47:40 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static	void		add_front_obj(t_object **head, t_object *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

static	void		add_front_cam(t_cam **head, t_cam *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

static	void		add_front_light(t_light **head, t_light *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

void				add_front(t_rt **r, void *new, int type)
{
	t_rt		*rt;

	rt = *r;
	if (type == 4)
		add_front_cam(&rt->cameras, new);
	else if (type == 5)
		add_front_light(&rt->lights, new);
	else
		add_front_obj(&rt->objects, new);
}

int				stock_vect3(t_vect3 *r, char *str)
{
	char	**split;
	int		i;
	double	d[3];

	i = 0;
	split = ft_strsplit(str, ' ');
	if (!split)
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
		d[i] = ft_atoi(split[i]);
		i++;
	}
	free_tab2(&split, len_tab_2d(split));
	if (i != 3)
		return (-1);
	r->x = d[0];
	r->y = d[1];
	r->z = d[2];
	return (1);
}

int				stock_rpa(double *dst, char *str)
{
	*dst = ft_atoi(str);
	return (1);
}

 static int  in_base(char c)
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

int				rgb_to_int(t_color v)
{
	return ((((int)v.x & 0xff) << 16) | (((int)v.y & 0xff) << 8) | ((int)v.z & 0xff));
}

int		is_hex(char *value)
{
	int	len;

	len = ft_strlen(value);
	if (len > 2 && len <= 10 && value[0] == '0'\
			&& (value[1] == 'x' || value[1] == 'X'))
		return (1);
	return (0);
}
int			to_rgb(t_color *co, int c)
{
	co->x = (c >> 16) & 255;
	co->y = (c >> 8) & 255;
	co->z = c & 255;
	return (1);
}

int	read_color(t_color *c, char *data)
{
	int		color;
	int		i;
	int		hex;
	int		digit;

	color = 0;
	if (!ft_isdigit(data[0]))
		return (to_rgb(c, color));
	hex = is_hex(data);
	i = hex ? 1 : -1;
	while (data && data[++i])
	{
		if	((digit = in_base(data[i])) < 0)
			return (0);
		color = color * (hex ? 16 : 10) + digit;
	}
	return (to_rgb(c, color));
}