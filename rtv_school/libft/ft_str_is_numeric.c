/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:17:08 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/27 14:46:38 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_numeric(char *str)
{
	int		i;
	int		p;

	p = 0;
	i = 0;
	if (str[i] && str[i] == '-')
	{
		if (str[1] == '.')
			return (0);
		i += 1;
	}
	else if (str[i] && str[0] == '.')
		return (0);
	while (str[i])
	{
		if (str[i] && str[i] == '.')
			p += 1;
		else if (str[i] && (str[i] < 48 || str[i] > 57))
			return (0);
		i += 1;
	}
	if (str[i - 1] == '.' || p > 1)
		return (0);
	return (1);
}
