/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 18:20:03 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color		paint(t_ray r, t_light *l, t_vect3 l_dir, t_vect3 tin)
{
	double	dist;

	dist = ft_magnitude(v_c_prod(r.direction, tin.x));
	if (tin.x > 0.0 && ((ft_magnitude(l_dir) < dist)) &&\
	(dot(r.direction, l->direct_dir)) < 0)
	{
		return (fraction(l->color, tin.y *\
			powf(dot(r.direction, l->direct_dir), 20)));
	}
	return ((t_color){0.0, 0.0, 0.0});
}

double		cast(t_rt *rt, t_ray r, t_light *l, double *ints)
{
	t_object	*obj;
	t_object	o;
	double		t;

	obj = rt->objects;
	*ints = l->intensity;
	t = -1.0;
	while (obj)
	{
		copy_obj(&o, obj);
		if ((t = rt->intersection[obj->type](&o, &r)) > 0.0 && !o.is_transp)
			break ;
		else if (t > 0 && o.is_transp)
			*ints *= o.is_transp;
		obj = obj->next;
	}
	return (t);
}

t_color		is_direct_light(t_rt *rt, t_ray r, double t)
{
	t_vect3		l_dir;
	double		ints;
	t_light		*l;
	t_color		blind;

	blind = (t_color){0.0f, 0.0f, 0.0f};
	l = rt->lights;
	while (rt->direct && l)
	{
		l->direct_dir =\
		normalize(vect_sub((t_vect3){0, 0, 0}, l->position));
		l_dir = vect_sub(l->position, rt->cameras->o);
		t = cast(rt, r, l, &ints);
		blind = add_color(blind, paint(r, l, l_dir, (t_vect3){t, ints, 0}));
		l = l->next;
	}
	return (blind);
}

int			parallel_light(t_rt *rt, t_ray r, t_light light)
{
	t_vect3		light_p;
	double		dott;

	light.direct_dir =
		normalize(vect_sub((t_vect3){0, -14, 40}, light.position));
	if (0 && rt->direct)
	{
		light_p = normalize(vect_sub(r.hit_point, light.position));
		if ((dott = dot(light_p, light.direct_dir)) > 0.9)
		{
			if (sqrtf(1.0 - dott * dott) < 0.1)
				return (1);
		}
		return (0);
	}
	return (1);
}

t_color		shade(t_rt *rt, t_light li, t_object obj, t_ray r)
{
	double	n_l;
	int		shadow;
	int		parallel;
	t_color	color;

	n_l = dot(obj.normal, li.direction);
	color = (t_color){0.0, 0.0, 0.0};
	r.refraction_index = obj.refraction_index;
	if (n_l > 0)
		color = vect_add(color, diffuse(&li, n_l, &obj));
	color = add_color(color, specular(&li, &r, &obj));
	color = add_color(color,\
	fraction(reflex_col(rt, r, &obj, &li), obj.is_ref));
	shadow = in_shadow(rt, &li, &obj);
	parallel = parallel_light(rt, r, li);
	color = add_color(color,\
	fraction(refract_color(rt, r, &obj, &li), obj.is_transp));
	color = fraction(color, parallel * shadow * li.intensity);
	return (color);
}

unsigned int	light_effect(t_rt *rt, t_object *o, t_ray *ray)
{
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;
	t_object		object;
	t_light			li;

	i = 0;
	lights = rt->lights;
	copy_obj(&object, o);
	tmp_res[1] = ambient(&object, rt->ambient);
	while (lights)
	{
		li.intensity = lights->intensity;
		li.color = lights->color;
		li.position = lights->position;
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		li.direction = vect_sub(li.position, ray->hit_point);
		li.d = sqrtf(dot(li.direction, li.direction));
		li.direction = normalize(li.direction);
		color[i++] = shade(rt, li, object, *ray);
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}


int		light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	if (close_obj->texture->type != NONE && (close_obj->type == SPHERE ||\
	close_obj->type == CYLINDER || close_obj->type == CONE ||\
	close_obj->type == PLANE))
		texture(&close_obj, ray->hit_point, rt->hooks);
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}
