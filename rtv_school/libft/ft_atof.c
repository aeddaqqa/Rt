/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:03:27 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/28 12:42:04 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double			whole_part;
	double			decimal_part;
	char			*point;
	int				i;
	int				sign;

	sign = 1;
	if (*str == '-' && str++)
		sign = -1;
	if (!(point = ft_strchr(str, '.')) || (point[1] && !ft_isdigit(point[1])))
		return (ft_atod(str) * sign);
	whole_part = ft_atod(str);
	decimal_part = ft_atod(&point[1]);
	i = 0;
	while (point[++i])
		if (!ft_isdigit(point[i]))
			break ;
	while (i > 1)
	{
		decimal_part = decimal_part / 10;
		i--;
	}
	return ((whole_part + decimal_part) * sign);
}
