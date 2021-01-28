/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:56:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/28 17:45:40 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			len_tab_2d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		free_tab2(char ***tab, int l)
{
	int		i;
	char	**t;

	t = *tab;
	i = 0;
	while (i < l)
	{
		free(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
}
