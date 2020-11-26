/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:32:27 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/20 13:51:01 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*step;

	if ((!lst && f))
		return (0);
	step = ft_lstnew(f(lst)->content, f(lst)->content_size);
	fresh = step;
	lst = lst->next;
	while (lst)
	{
		step->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		step = step->next;
		lst = lst->next;
	}
	step = NULL;
	return (fresh);
}
