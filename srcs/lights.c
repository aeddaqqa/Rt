/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:28:54 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_color			ambient(t_obj *obj)
{
	t_color		color;

	color = multip_vec_const((t_color){1.0, 1.0, 1.0}, obj->ambient);
	color = multip_vector(color, obj->color);
	return (color);
}

static int				in_shadow(t_rt *rt, t_light *light, t_obj *object)
{
	t_obj	*obj;
	double	t;
	double	distance;
	t_ray	shadow;

	shadow.origin = light->pos;
	shadow.direction = multip_vec_const(light->dir, -1.0);
	obj = rt->objects;
	while (obj)
	{
		if (obj != object\
				&& (t = rt->hit_object[obj->type](obj, &shadow)) > 0.0)
		{
			shadow.hit_point = multip_vec_const(shadow.direction, t);
			distance = sqrtf(dot_prod(shadow.hit_point, shadow.hit_point));
			if (distance < light->d)
				return (0);
		}
		obj = obj->next;
	}
	return (1);
}

static t_color			diffuse(t_light *light, double n_l, t_obj *object)
{
	t_color		color;

	color =\
		multip_color(fraction(light->color, light->intensity), object->color);
	color = fraction(color, n_l * object->diffuse);
	return (color);
}

static t_color			specular(t_light *l, t_ray *ray, t_obj *object)
{
	t_color			color;
	t_vector		h;
	unsigned int	alpha;
	double			dot;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(sub_vector(l->dir, ray->direction));
	if ((dot = dot_prod(object->normal, h)) <= 0)
		return (color);
	dot = powf(dot, alpha);
	color = fraction(l->color, dot * object->specular * l->intensity);
	return (color);
}

unsigned int			light_effect(t_rt *rt, t_obj *object, t_ray *ray)
{
	double			n_l;
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;

	i = 0;
	lights = rt->lights;
	tmp_res[1] = ambient(object);
	while (lights)
	{
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		lights->dir = sub_vector(lights->pos, ray->hit_point);
		lights->d = sqrtf(dot_prod(lights->dir, lights->dir));
		lights->dir = normalize(lights->dir);
		n_l = dot_prod(object->normal, lights->dir);
		if (n_l > 0)
			tmp_res[0] = add_vector(tmp_res[0], diffuse(lights, n_l, object));
		tmp_res[0] = add_color(tmp_res[0], specular(lights, ray, object));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, lights, object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}
