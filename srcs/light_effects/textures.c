/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:33 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/07 15:18:20 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		texture_clr(t_object **object, t_point hit)
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
		v = (-hit.y + 10.0) / 20.0;
		v = fabs(fmod(v, 1.0));
	}
	u *= obj->texture->w;
	v *= obj->texture->h;
	if ((int)v * obj->texture->w + (int)u < (obj->texture->w * obj->texture->h))
		obj->color = inttorgb(obj->texture->data_pixels\
				[(int)v * obj->texture->w + (int)u]);
}

static void		texture_clr_plane_board(t_object **object, t_point hit)
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

static void		texture_clr_board(t_object **object, t_point hit)
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
		v = (-hit.y + 10.0) / 20.0;
		v = fabs(fmod(v, 1.0));
	}
	u *= 40;
	v *= 40;
	if ((int)((int)u + (int)v) % 2 == 0)
		obj->color = (t_vect3){1.0, 1.0, 1.0};
	else
		obj->color = (t_vect3){.0, .0, .0};
}

static void		texture_clr_plane(t_object **object, t_point hit)
{
	double		u;
	double		v;
	t_object	*obj;

	obj = *object;
	v = hit.z / 10.0;
	u = hit.x / 10.0;
	v = v - floor(v);
	u = u - floor(u);
	u *= obj->texture->w;
	v *= obj->texture->h;
	if ((int)v * obj->texture->w + (int)u < (obj->texture->w * obj->texture->h))
		obj->color = inttorgb(obj->texture->data_pixels[(int)v *
				obj->texture->w +
				(int)u]);
}

void			texture(t_object **object, t_point hit)
{
	if ((*object)->texture->type == TEX)
	{
		if ((*object)->type == PLANE)
			texture_clr_plane(object, hit);
		else
			texture_clr(object, hit);
	}
	if ((*object)->texture->type == BOARD)
	{
		if ((*object)->type == PLANE)
			texture_clr_plane_board(object, hit);
		else
			texture_clr_board(object, hit);
	}
	if ((*object)->texture->type == SPECTRUM)
	{
		if ((*object)->type == PLANE)
			texture_wave_effect_plane(object, hit);
		else
			texture_wave_effect(object, hit);
	}
}
