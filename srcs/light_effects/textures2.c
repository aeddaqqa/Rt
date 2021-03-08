/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:19:40 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 18:31:29 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	apply_texture(t_object *obj, double uv[2])
{
	uv[0] *= obj->texture->w;
	uv[1] *= obj->texture->h;
	if ((int)uv[1] * obj->texture->w +\
			(int)uv[0] < (obj->texture->w * obj->texture->h)\
			&& (int)uv[1] * obj->texture->w + (int)uv[0] > 0)
		obj->color = inttorgb(obj->texture->data_pixels\
				[(int)uv[1] * obj->texture->w + (int)uv[0]]);
}

int		texture_clr(t_object **object, t_point hit, double tab[2])
{
	double		ph_th[2];
	double		uv[2];
	t_object	*obj;

	obj = *object;
	ph_th[0] = atan2(hit.z, hit.x);
	uv[0] = (-ph_th[0] + (M_PI)) / (double)((2.0 * M_PI + 1.0 * tab[1]));
	if (obj->type == SPHERE)
	{
		ph_th[1] = (double)(hit.y / (obj->radius + M_PI * tab[0]));
		if (obj->texture->slice && (ph_th[1] > 1.0 || ph_th[1] < -1.0))
			return (0);
		ph_th[1] = acos(ph_th[1]);
		uv[1] = ph_th[1] / M_PI;
	}
	else
	{
		uv[1] = (-hit.y + (*object)->height) / ((*object)->height *\
				(2.0 + 1.9 * tab[0]));
		if (obj->texture->slice && (uv[1] > 1.0 || uv[1] < -1.0))
			return (0);
		uv[1] = fabs(fmod(uv[1], 1.0));
	}
	apply_texture(obj, uv);
	return (1);
}
