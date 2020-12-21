/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:46:20 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/19 14:31:38 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = NULL;
	if (!(fresh = malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		fresh->next = NULL;
	}
	else
	{
		fresh->content_size = content_size;
		fresh->content = malloc((content_size + 1) * sizeof(*content));
		if (fresh->content == NULL)
			return (0);
		fresh->content = ft_memmove(fresh->content, content
				, content_size);
		fresh->next = NULL;
	}
	return (fresh);
}
