/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:08:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:36:10 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	free_objects(t_rt *r)
{
	void	*tmp;

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
}

static void	free_lights(t_rt *r)
{
	void	*tmp;

	while (r->lights)
	{
		tmp = r->lights->next;
		free(r->lights);
		r->lights = tmp;
	}
}

static void	free_camera(t_rt *r)
{
	void	*tmp;

	while (r->cameras)
	{
		tmp = r->cameras->next;
		free(r->cameras);
		r->cameras = tmp;
	}
}

void		free_rt(t_rt **rt)
{
	t_rt	*r;

	r = *rt;
	if (r)
	{
		free_objects(r);
		free_lights(r);
		free_camera(r);
		free(r);
	}
}
