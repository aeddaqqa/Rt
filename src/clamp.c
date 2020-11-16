/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:37:49 by chzabakh          #+#    #+#             */
/*   Updated: 2020/11/07 09:33:42 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		clamp(float value, float min, float max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}
	return (value);
}

t_vec		clamp_vec(t_vec v)
{
	v.x = clamp(v.x * 255., 0.0f, 255.0f);
	v.y = clamp(v.y * 255., 0.0f, 255.0f);
	v.z = clamp(v.z * 255., 0.0f, 255.0f);
	return (v);
}

int			rgb_to_int(t_vec v)
{
	int red;
	int green;
	int blue;
	int rgb;

	red = (int)v.x;
	green = (int)v.y;
	blue = (int)v.z;
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

float		convert(float ang)
{
	return (ang * M_PI / 180);
}

t_vec		amb(t_vec color, t_vec lit_clr, t_vec hit_obj_clr)
{
	color.x = color.x + 0.02 * lit_clr.x * hit_obj_clr.x;
	color.y = color.y + 0.02 * lit_clr.y * hit_obj_clr.y;
	color.z = color.z + 0.02 * lit_clr.z * hit_obj_clr.z;
	return (color);
}
