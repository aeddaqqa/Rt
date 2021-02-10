/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 18:32:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

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
		lights->dir = vect_sub(lights->position, ray->hit_point);
		lights->d = sqrtf(dot(lights->dir, lights->dir));
		lights->dir = normalize(lights->dir);
		n_l = dot(object->orientation, lights->dir);
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(lights, n_l, object));
		tmp_res[0] = add_color(tmp_res[0], specular(lights, ray, object));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, lights, object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}
