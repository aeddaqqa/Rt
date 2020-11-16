/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:42:32 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int		is_angle(enum e_object_type type, char *value)
{
	return (type == CONE && is_scalar(value) == 'g');
}

static int		numberofcomponents(enum e_object_type type)
{
	if (type == CONE)
		return (7);
	if (type == SPHERE)
		return (6);
	if (type == CYLINDER)
		return (7);
	if (type == PLANE)
		return (6);
	return (0);
}

static t_obj	*init_object(t_rt *rt, enum e_object_type type)
{
	t_obj		*new;

	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		destroy(rt, MALLOC_ERROR);
	new->type = type;
	new->rayon = -1.0;
	new->pos = rt->null;
	new->normal = rt->null;
	new->color = (t_color)rt->null;
	new->color.x = -1.0;
	new->angle = -1.0;
	new->diffuse = -1.0;
	new->ambient = -1.0;
	new->specular = -1.0;
	new->vect_ori = (t_vector){0.0, 1.0, 0.0};
	new->rot = new->vect_ori;
	return (new);
}

void			parse_objects(t_rt *rt, int fd, enum e_object_type type)
{
	t_obj		*new;
	char		**s;
	int			comp;

	comp = numberofcomponents(type) + 1;
	new = init_object(rt, type);
	while (--comp)
	{
		if (!(s = value(rt, fd)) || check_argument(rt, new, &s))
			continue;
		is_vect(s[0]) == 'o' ? new->pos = read_vector(&s[1]) : rt->null;
		type != SPHERE && is_vect(s[0]) == 't' ? new->vect_ori =\
		normalize(rotation_xyz(new->vect_ori, read_vector(&s[1]))) : rt->null;
		is_angle(type, s[0]) ? new->angle = read_scalar(&s[1]) * PI / 180.0 : 0;
		type != PLANE && type != CONE &&\
			is_scalar(s[0]) == 'r' ? new->rayon = read_scalar(&s[1]) : 0;
		is_scalar(s[0]) == 'c' ? new->color = read_color(&s[1]) : rt->null;
		is_scalar(s[0]) == 'd' ? new->diffuse = read_scalar(&s[1]) / 100.0 : 0;
		is_scalar(s[0]) == 'a' ? new->ambient = read_scalar(&s[1]) / 100.0 : 0;
		is_scalar(s[0]) == 's' ? new->specular = read_scalar(&s[1]) / 100.0 : 0;
		free_double_ptr(&s);
	}
	is_valid_object(rt, new, type);
	new->next = rt->objects;
	rt->objects = new;
}
