/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:08:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/05 09:29:01 by aeddaqqa         ###   ########.fr       */
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
			if (r->objects->texture)
			{
				if (r->objects->texture->data_pixels)
					free(r->objects->texture->data_pixels);
				free(r->objects->texture);
			}
			free(r->objects);
			r->objects = tmp;
		}
		while (r->lights)
		{
			tmp = r->lights->next;
			free(r->lights);
			r->lights = tmp;
		}
		while (r->cameras)
		{
			tmp = r->cameras->next;
			free(r->cameras);
			r->cameras = tmp;
		}
		free(r);
	}
}
