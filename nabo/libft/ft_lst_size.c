/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:33:46 by nabouzah          #+#    #+#             */
/*   Updated: 2019/05/06 18:15:24 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_size(t_list *begin_list)
{
	int		i;

	i = 0;
	if (begin_list == NULL)
		return (i);
	while (begin_list != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
