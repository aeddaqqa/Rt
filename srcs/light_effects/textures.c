/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:33 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 18:30:51 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	texture_clr_plane_board(t_object **object, t_point hit)
{
	double		u;
	double		v;
	t_object	*obj;

	obj = *object;
	v = hit.z / 100.0;
	u = hit.x / 100.0;
	v = v - floor(v);
	u = u - floor(u);
	u *= 40;
	v *= 40;
	if ((int)((int)u + (int)v) % 2 == 0)
		obj->color = (t_vect3){1.0, 1.0, 1.0};
	else
		obj->color = (t_vect3){.0, .0, .0};
}

static void	texture_clr_board(t_object **object, t_point hit)
{
	double		phi;
	double		theta;
	double		u;
	double		v;
	t_object	*obj;

	obj = *object;
	phi = atan2(hit.z, hit.x);
	u = (-phi + (M_PI)) / (double)(2.0 * M_PI);
	if (obj->type == SPHERE)
	{
		theta = acos((double)(hit.y / obj->radius));
		v = theta / M_PI;
	}
	else
	{
		v = (-hit.y + (*object)->height) / ((*object)->height * 2.0);
		v = fabs(fmod(v, 1.0));
	}
	u *= 40;
	v *= 40;
	if ((int)((int)u + (int)v) % 2 == 0)
		obj->color = (t_vect3){1.0, 1.0, 1.0};
	else
		obj->color = (t_vect3){.0, .0, .0};
}

static int	texture_clr_plane(t_object **object, t_point hit, double tab[2])
{
	double		u;
	double		v;
	t_object	*obj;
	int			var;

	obj = *object;
	var = 100 * tab[0];
	var = (var == -100) ? 0 : var;
	v = hit.z / (1.0 + var) + tab[1];
	u = hit.x / (1.0 + var) + tab[1];
	if (obj->texture->slice && (v > 1.0 || v < -1.0 || u > 1.0 || u < -1.0))
		return (0);
	v = v - floor(v);
	u = u - floor(u);
	u *= obj->texture->w;
	v *= obj->texture->h;
	if ((int)v * obj->texture->w + (int)u < (obj->texture->w * obj->texture->h))
		obj->color = inttorgb(obj->texture->data_pixels[(int)v *
				obj->texture->w + (int)u]);
	return (1);
}

void		texture2(t_object **object, t_point p)
{
	if ((*object)->type == PLANE)
		texture_wave_effect_plane(object, p);
	else
		texture_wave_effect(object, p);
}

int			texture(t_object **object, t_point hit, double tab[2])
{
	t_point p;

	p = vect_sub(hit, (*object)->position);
	p = rotation_xyz(p, vect_sub((t_vect3){0, 0, 0}, (*object)->rotation));
	if ((*object)->texture->type == TEX)
	{
		if ((*object)->type == PLANE)
			return (texture_clr_plane(object, p, tab));
		else
			return (texture_clr(object, p, tab));
	}
	if ((*object)->texture->type == BOARD)
	{
		if ((*object)->type == PLANE)
			texture_clr_plane_board(object, p);
		else
			texture_clr_board(object, p);
	}
	if ((*object)->texture->type == SPECTRUM)
		texture2(object, p);
	return (1);
}
