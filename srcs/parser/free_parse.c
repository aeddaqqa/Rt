/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:08:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 17:27:55 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		free_rt(t_rt **rt)
{
	t_rt	*r;
	void	*tmp;

	r = *rt;
	if (r)
	{
		while (r->objects)
		{
			tmp = r->objects->next;
			free(r->objects);
			r->objects = tmp;
		}
		while (r->lights)
		{
			tmp = r->lights->next;
			free(r->lights);
			r->lights = tmp;
		}
		free(r->cameras);
		free(r);
	}
}
