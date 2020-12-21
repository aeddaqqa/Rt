/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:30:00 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/10 15:40:24 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	while (*alst != NULL)
	{
		elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = elem;
	}
}
