/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:36:51 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 19:14:05 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// static t_color			paint(t_ray r, t_light *l, t_vect3 l_dir, t_vect3 tin)
// {
// 	double	dist;

// 	dist = ft_magnitude(v_c_prod(r.direction, tin.x));
// 	if (tin.x > 0.0 && ((ft_magnitude(l_dir) < dist)) &&\
// 	(dot(r.direction, l->direct_dir)) < 0)
// 	{
// 		return (fraction(l->color, tin.y *\
// 			powf(dot(r.direction, l->direct_dir), 50)));
// 	}
// 	return ((t_color){0.0, 0.0, 0.0});
// }

// static double			cast(t_rt *rt, t_ray r, t_light *l, double *ints)
// {
// 	t_object	*obj;
// 	t_object	o;
// 	double		t;

// 	obj = rt->objects;
// 	*ints = l->intensity;
// 	t = -1.0;
// 	while (obj)
// 	{
// 		copy_obj(&o, obj);
// 		if ((t = rt->intersection[obj->type](&o, &r)) > 0.0 && !o.is_transp)
// 			break ;
// 		else if (t > 0 && o.is_transp)
// 			*ints *= o.is_transp;
// 		obj = obj->next;
// 	}
// 	return (t);
// }

// t_color					is_direct_light(t_rt *rt, t_ray r, double t)
// {
// 	t_vect3		l_dir;
// 	double		ints;
// 	t_light		l;
// 	t_light		*light;
// 	t_color		blind;

// 	blind = (t_color){0.0f, 0.0f, 0.0f};
// 	light = rt->lights;
// 	while (rt->direct && light)
// 	{
// 		l = *light;
// 		l.direct_dir =\
// 		normalize(vect_sub((t_vect3){0, 0, 0}, l.position));
// 		l_dir = vect_sub(l.position, rt->cameras->o);
// 		t = cast(rt, r, &l, &ints);
// 		blind = add_color(blind, paint(r, &l, l_dir, (t_vect3){t, ints, 0}));
// 		light = light->next;
// 	}
// 	return (blind);
// }

t_color	is_direct_light(t_rt *rt, t_ray r, double t)
{
	t_vect3		light_dir;
	double		hit_dist;
	double		ret;
	t_light		*light;
	t_light		lght;
	t_object	*obj;
	t_object	o;
	t_color		blind;

	blind = (t_color){0.0f, 0.0f, 0.0f};
	light = rt->lights;
	obj = rt->objects;
	rt->lights->direct_dir = normalize(vect_sub((t_vect3){0, 0, 0}, rt->lights->position));
	while (rt->direct && light)
	{
		// lght.intensity = light->intensity;
		// lght.direct_dir = light->direct_dir;
		lght = *light;
		light_dir = vect_sub(light->position, rt->cameras->o);
		while (obj)
		{
			hit_dist = INFINITY;
			copy_obj(&o, obj);
			if ((t = rt->intersection[obj->type](&o, &r)) > 0.0 && !o.is_transp)
			{
				hit_dist = ft_magnitude(v_c_prod(r.direction, t));
				break ;
			}
			else if (t > 0 && o.is_transp)
				lght.intensity *= o.is_transp;
			obj = obj->next;
		}
		if (((ft_magnitude(light_dir) < hit_dist)) &&
			(ret = dot(r.direction, lght.direct_dir)) < 0)
			blind = add_color(blind,\
			fraction(lght.color, lght.intensity * powf(dot(r.direction, lght.direct_dir), 50)));
		light = light->next;
	}
	return (blind);
}
