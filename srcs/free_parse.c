/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:08:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/21 05:27:34 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
			r->objects = NULL;
			r->objects = tmp;
		}
		while (r->lights)
		{
			tmp = r->lights->next;
			free(r->lights);
			r->lights = NULL;
			r->lights = tmp;
		}
		while (r->cameras)
		{
			tmp = r->cameras->next;
			free(r->cameras);
			r->cameras = NULL;
			r->cameras = tmp;
		}
		free(r);
		r = NULL;
	}
}
