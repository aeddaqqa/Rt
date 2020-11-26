/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:55:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:18:33 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		is_scalar(char *id)
{
	if (!ft_strcmp(id, "radius"))
		return ('r');
	else if (!ft_strcmp(id, "fov"))
		return ('f');
	else if (!ft_strcmp(id, "color"))
		return ('c');
	else if (!ft_strcmp(id, "diffuse"))
		return ('d');
	else if (!ft_strcmp(id, "specular"))
		return ('s');
	else if (!ft_strcmp(id, "ambient"))
		return ('a');
	else if (!ft_strcmp(id, "angle"))
		return ('g');
	else if (!ft_strcmp(id, "intensity"))
		return ('i');
	return (0);
}

int		is_vect(char *id)
{
	if (!ft_strcmp(id, "origin"))
		return ('o');
	if (!ft_strcmp(id, "up"))
		return ('u');
	if (!ft_strcmp(id, "lookat"))
		return ('l');
	if (!ft_strcmp(id, "pos"))
		return ('o');
	if (!ft_strcmp(id, "ori") || !ft_strcmp(id, "rot"))
		return ('t');
	if (!ft_strcmp(id, "normal"))
		return ('n');
	return (0);
}

void	is_valid_object(t_rt *rt, t_obj *obj, enum e_object_type type)
{
	if (obj->specular < 0 || obj->diffuse < 0 || obj->ambient < 0\
			|| obj->color.x < 0 || (type == CONE && obj->angle < 0)\
			|| (type != CONE && type != PLANE && obj->rayon < 0))
		destroy(rt, OBJECT_PROPERTY);
}

int		is_object(char *value)
{
	if (!ft_strcmp(value, "plane") || !ft_strcmp(value, "sphere")\
			|| !ft_strcmp(value, "cylinder") || !ft_strcmp(value, "cone"))
		return (1);
	return (0);
}

int		is_hex(char *value)
{
	int	len;

	len = ft_strlen(value);
	if (len > 2 && len <= 10 && value[0] == '0'\
			&& (value[1] == 'x' || value[1] == 'X'))
		return (1);
	return (0);
}
