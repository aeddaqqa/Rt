/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/07 06:06:29 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	rot_x(t_vector v, double angle)
{
	t_vector	result;
	double		delta;

	delta = angle * (PI / 180.0);
	result.x = v.x;
	result.y = v.y * cos(delta) - v.z * sin(delta);
	result.z = v.y * sin(delta) + v.z * cos(delta);
	return (result);
}

t_vector	rot_y(t_vector v, double angle)
{
	t_vector	result;
	double		delta;

	delta = angle * (PI / 180.0);
	result.x = v.x * cos(delta) + v.z * sin(delta);
	result.y = v.y;
	result.z = v.z * cos(delta) - v.x * sin(delta);
	return (result);
}

t_vector	rot_z(t_vector v, double angle)
{
	t_vector	result;
	double		delta;

	delta = angle * (PI / 180.0);
	result.x = v.x * cos(delta) - v.y * sin(delta);
	result.y = v.x * sin(delta) + v.y * cos(delta);
	result.z = v.z;
	return (result);
}

t_vector	rotation_xyz(t_vector v, t_vector a)
{
	t_vector	result;

	result = rot_x(v, a.x);
	result = rot_y(result, a.y);
	result = rot_z(result, a.z);
	return (result);
}
