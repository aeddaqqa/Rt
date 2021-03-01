/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:39:07 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/01 18:22:10 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	rot_x(t_vect3 v, double angle)
{
	t_vect3	result;
	double		delta;

	delta = angle * (M_PI / 180.0);
	result.x = v.x;
	result.y = v.y * cos(delta) - v.z * sin(delta);
	result.z = v.y * sin(delta) + v.z * cos(delta);
	return (result);
}

t_vect3	rot_y(t_vect3 v, double angle)
{
	t_vect3	result;
	double		delta;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) + v.z * sin(delta);
	result.y = v.y;
	result.z = v.z * cos(delta) - v.x * sin(delta);
	return (result);
}

t_vect3	rot_z(t_vect3 v, double angle)
{
	t_vect3	result;
	double		delta;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) - v.y * sin(delta);
	result.y = v.x * sin(delta) + v.y * cos(delta);
	result.z = v.z;
	return (result);
}

t_vect3	rotation_xyz(t_vect3 v, t_vect3 a)
{
	t_vect3	result;

	result = rot_x(v, a.x);
	result = rot_y(result, a.y);
	result = rot_z(result, a.z);
	return (result);
}

static	void		add_front_obj(t_object **head, t_object *new)
{
	new->orientation = rotation_xyz(new->orientation, new->rotation);
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
