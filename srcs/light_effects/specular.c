/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:14:45 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/28 08:48:36 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color			specular(t_light *l, t_ray *ray, t_object *object)
{
	t_color			color;
	t_vect3		h;
	unsigned int	alpha;
	double			dot_p;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->direction, ray->direction));
	if ((dot_p = dot(object->normal, h)) <= 0)
		return (color);
	dot_p = powf(dot_p, alpha);
	color = fraction(l->color, dot_p * l->intensity * SPECULER); // TODO: specular intensity
	return (color);
}