/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 16:43:22 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

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
		lght.intensity = light->intensity;
		lght.direct_dir = light->direct_dir;
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
			(ret = dot(r.direction, light->direct_dir)) < 0)
			blind = add_color(blind,\
			fraction(light->color, lght.intensity * powf(dot(r.direction, light->direct_dir), 20)));
		light = light->next;
	}
	return (blind);
}

unsigned int	light_effect(t_rt *rt, t_object *o, t_ray *ray)
{
	double			n_l;
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
		n_l = dot(object.normal, li.direction);
		ray->refraction_index = object.refraction_index;
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(&li, n_l, &object));
		tmp_res[0] = add_color(tmp_res[0], specular(&li, ray, &object));
		tmp_res[0] = add_color(tmp_res[0],\
		fraction(reflex_col(rt, *ray, &object, lights), object.is_ref));
		tmp_res[0] = add_color(tmp_res[0],\
		fraction(refract_color(rt, *ray, &object, lights), object.is_transp));
		color[i++] = fraction(tmp_res[0],\
		in_shadow(rt, &li, &object) * li.intensity);
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}

int		light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	int		color;
	double	n_l;
	t_vect3	dir;

	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	if (close_obj->texture->type != NONE && (close_obj->type == SPHERE ||\
	close_obj->type == CYLINDER || close_obj->type == CONE ||\
	close_obj->type == PLANE))
		texture(&close_obj, ray->hit_point, rt->hooks);
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}
