/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/08 11:50:30 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				parallel_light(t_ray r, t_light light)
{
	t_vect3		light_p;
	double		dott;

	light.look_at = (t_vect3){0, 0, 0}; // to rm
	light.direction =
		normalize(vect_sub(light.look_at, light.position));
	if (light.type == PARALLEL)
	{
		light_p = normalize(vect_sub(r.hit_point, light.position));
		if ((dott = dot(light_p, light.direction)) > 0.9)
		{
			if (sqrtf(1.0 - dott * dott) < 0.1)
				return (1);
		}
		return (0);
	}
	return (1);
}

t_color			shade(t_rt *rt, t_light li, t_object obj, t_ray r)
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
	parallel = parallel_light(r, li);
	color = add_color(color,\
	fraction(refract_color(rt, r, &obj, &li), obj.is_transp));
	color = fraction(color, parallel * shadow * li.intensity);
	return (color);
}

unsigned int	light_effect(t_rt *rt, t_object *o, t_ray *ray)
{
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			f_color;
	t_light			*lights;
	t_light			li;

	i = 0;
	lights = rt->lights;
	f_color = ambient(o, rt->ambient);
	while (lights)
	{
		li = *lights;
		li.direction = vect_sub(li.position, ray->hit_point);
		li.d = sqrtf(dot(li.direction, li.direction));
		li.direction = normalize(li.direction);
		color[i++] = shade(rt, li, *o, *ray);
		lights = lights->next;
	}
	while (i > 0)
		f_color = add_color(color[--i], f_color);
	return (rgb(f_color));
}

int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	if (close_obj->texture->type != NONE && (close_obj->type == SPHERE ||\
	close_obj->type == CYLINDER || close_obj->type == CONE ||\
	close_obj->type == PLANE))
		if (!(texture(&close_obj, ray->hit_point, rt->hooks)))
			return (0);
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}
