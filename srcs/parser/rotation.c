/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:57:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:57:44 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	rot_x(t_vect3 v, double angle)
{
	double		delta;
	t_vect3		result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x;
	result.y = v.y * cos(delta) - v.z * sin(delta);
	result.z = v.y * sin(delta) + v.z * cos(delta);
	return (result);
}

t_vect3	rot_y(t_vect3 v, double angle)
{
	double		delta;
	t_vect3		result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) + v.z * sin(delta);
	result.y = v.y;
	result.z = v.z * cos(delta) - v.x * sin(delta);
	return (result);
}

t_vect3	rot_z(t_vect3 v, double angle)
{
	double		delta;
	t_vect3		result;

	delta = angle * (M_PI / 180.0);
	result.x = v.x * cos(delta) - v.y * sin(delta);
	result.y = v.x * sin(delta) + v.y * cos(delta);
	result.z = v.z;
	return (result);
}

t_vect3	rotation_xyz(t_vect3 v, t_vect3 a)
{
	t_vect3	result;

	result = rot_x(v, a.x);
	result = rot_y(result, a.y);
	result = rot_z(result, a.z);
	return (result);
}
