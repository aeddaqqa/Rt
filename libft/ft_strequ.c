/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:13:25 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/15 00:15:54 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!(s1 && s2))
		return (0);
	if ((ft_strlen(s1) != ft_strlen(s2)) || ft_strcmp(s1, s2) != 0)
		return (0);
	return (1);
}
