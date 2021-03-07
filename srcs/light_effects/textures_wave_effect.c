/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_wave_effect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:09:41 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/07 15:56:07 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double		min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static double		max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

void				texture_wave_effect(t_object **object, t_point hit)
{
	double		theta;
	double		u;
	double		v;
	t_color		rgb;

	u = (-atan2(hit.z, hit.x) + (M_PI)) / (double)(2.0 * M_PI);
	if ((*object)->type == SPHERE)
	{
		theta = acos((double)(hit.y / (*object)->radius));
		v = theta / M_PI;
	}
	else
	{
		v = (-hit.y + (*object)->height) / ((*object)->height * 2.0);
		v = fabs(fmod(v, 1.0));
	}
	theta = (5.0 * M_PI * v) / (3 * u) + (M_PI / 2.0);
	rgb.x = sin(theta) * 192 + 128;
	rgb.x = max(0, min(255, rgb.x));
	rgb.y = sin(theta - (2.0 * M_PI) / 3.0) * 192.0 + 128.0;
	rgb.y = max(0, min(255, rgb.y));
	rgb.z = sin(theta - (4.0 * M_PI) / 3.0) * 192 + 128;
	rgb.z = max(0, min(255, rgb.z));
	(*object)->color = v_c_prod(rgb, 1.0 / 255.0);
}

void				texture_wave_effect_plane(t_object **object, t_point hit)
{
	double		theta;
	double		u;
	double		v;
	t_color		rgb;

	v = hit.z / 30.0;
	u = hit.x / 30.0;
	v = (v - floor(v)) * 40;
	u = (u - floor(u)) * 40;
	theta = (5.0 * M_PI * v) / (3 * u) + (M_PI / 2.0);
	rgb.x = sin(theta) * 192 + 128;
	rgb.x = max(0, min(255, rgb.x));
	rgb.y = sin(theta - (2.0 * M_PI) / 3.0) * 192.0 + 128.0;
	rgb.y = max(0, min(255, rgb.y));
	rgb.z = sin(theta - (4.0 * M_PI) / 3.0) * 192 + 128;
	rgb.z = max(0, min(255, rgb.z));
	(*object)->color = v_c_prod(rgb, 1.0 / 255.0);
}
