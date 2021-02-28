/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/28 18:41:14 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color	multip_color(t_color c1, t_color c2)
{
	t_color	new;
	float	tmp;

	tmp = c1.x * c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y * c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.z * c2.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

t_color	fraction(t_color c, double fract)
{
	t_color	new;
	double	tmp;

	tmp = c.x * fract;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.y * fract;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.z * fract;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

int		rgb(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x * 255;
	ptr[1] = color.y * 255;
	ptr[0] = color.z * 255;
	ptr[3] = 0;
	return (new);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	new;
	double	tmp;

	tmp = c1.x + c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y + c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c2.z + c1.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

unsigned int			light_effect(t_rt *rt, t_object *object, t_ray *ray) //TODO : static
{
	double			n_l;
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;
	t_light			li;

	i = 0;
	lights = rt->lights;
	tmp_res[1] = ambient(object, rt->ambient);
	while (lights)
	{
		li.intensity = lights->intensity;
		li.color = lights->color;
		li.position = lights->position;
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		li.direction = vect_sub(li.position, ray->hit_point);
		li.d = sqrtf(dot(li.direction, li.direction));
		li.direction = normalize(li.direction);
		n_l = dot(object->normal, li.direction);
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(&li, n_l, object));
		tmp_res[0] = add_color(tmp_res[0], specular(&li, ray, object));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, &li, object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}

int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	int color;
	double n_l;
	t_vect3 dir;

	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}