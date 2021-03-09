/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:39:07 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/09 11:36:07 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static	void		add_front_obj(t_object **head, t_object *new)
{
	new->orientation = rotation_xyz(new->orientation, new->rotation);
	new->position = vect_add(new->position, new->translation);
	set_matter(new);
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

static	void		add_front_cam(t_cam **head, t_cam *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			(*head)->prev = new;
			new->next = *head;
			*head = new;
		}
	}
}

static	void		add_front_light(t_light **head, t_light *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

void				add_front(t_rt **r, void *new, int type)
{
	t_rt		*rt;

	rt = *r;
	if (type == 4)
		add_front_cam(&rt->cameras, new);
	else if (type == 5)
		add_front_light(&rt->lights, new);
	else
		add_front_obj(&rt->objects, new);
}
