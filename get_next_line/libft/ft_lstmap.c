/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:10:23 by chzabakh          #+#    #+#             */
/*   Updated: 2019/04/20 14:02:51 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *fresh;

	fresh = ft_lstnew(f(lst)->content, f(lst)->content_size);
	lst = lst->next;
	temp = fresh;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		lst = lst->next;
		temp = temp->next;
	}
	free(temp);
	return (fresh);
}
