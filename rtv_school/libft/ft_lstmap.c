/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:39:29 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/13 13:32:40 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *fresh;

	if (lst)
	{
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
	return (NULL);
}
