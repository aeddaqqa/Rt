/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:53:30 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 18:55:02 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		rgba(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x;
	ptr[1] = color.y;
	ptr[0] = color.z;
	ptr[3] = 0;
	return (new);
}

int     ft_shade_object(t_hit *hit /*, t_light *lights, t_object *lst , t_ray *ray*/)
{
    // t_light     *light;
    // t_vect3       color;
    // t_vect3       light_dir;
    // // t_ray       shadow_ray;
    // double       t;

    // color = (t_vect3){0.0f, 0.0f, 0.0f};
    // shadow_ray.source = hit->p;
    // light = lights;
    // while (light)
    // {
    //     // light_dir = ft_normalize(vect_add(light->position, hit->p));
    //     // shadow_ray.direction = light_dir;
    //     // t = ft_magnitude(vect_add(light->position, hit->p));
    //     // if (!shadow_cast(lst, &shadow_ray, &t))
    //         // color = ft_vect3toradd(color, ft_lgt_computing(light, light_dir,\
    //     hit, ray));
    //     light = light->next;
    // }
    return (rgba(hit->object->color));
}