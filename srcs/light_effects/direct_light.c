/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:36:51 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/08 12:41:22 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_color			cast(t_rt *rt, t_ray r, t_light l, t_vect3 l_dir)
{
	t_object	*obj;
	t_object	o;
	double		t;
	double		dist;

	obj = rt->objects;
	dist = INFINITY;
	while (obj)
	{
		copy_obj(&o, obj);
		if ((t = rt->intersection[obj->type](&o, &r)) > 0.0 && !o.is_transp)
		{
			dist = ft_magnitude(v_c_prod(r.direction, t));
			break ;
		}
		else if (t > 0.0 && o.is_transp)
			l.intensity *= o.is_transp;
		obj = obj->next;
	}
	if (((ft_magnitude(l_dir) < dist)) && (dot(r.direction, l.direction)) < 0)
	{
		return (fraction(l.color, l.intensity *\
			powf(dot(r.direction, l.direction), 50)));
	}
	return ((t_color){0.0, 0.0, 0.0});
}

t_color					is_direct_light(t_rt *rt, t_ray r, double t)
{
	t_vect3		l_dir;
	t_light		l;
	t_light		*light;
	t_color		blind;

	blind = (t_color){0.0f, 0.0f, 0.0f};
	light = rt->lights;
	while (light)
	{
		l = *light;
		t = -1;
		if (l.type == DIRECT)
		{
			l.direction =\
			normalize(vect_sub(l.look_at, l.position));
			l_dir = vect_sub(l.position, rt->cameras->o);
			blind = add_color(blind, cast(rt, r, l, l_dir));
		}
		light = light->next;
	}
	return (blind);
}
