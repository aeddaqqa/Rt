/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:43:24 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/04/13 15:58:49 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		link->next = NULL;
	}
	else
	{
		if (!(link->content = (void *)malloc(sizeof(*content) * content_size)))
			return (NULL);
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
		link->next = NULL;
	}
	return (link);
}
