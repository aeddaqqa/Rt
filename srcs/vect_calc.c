/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:35:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/07 05:40:16 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	add_vector(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vector	sub_vector(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vector	multip_vector(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.x * v.x;
	w.y = u.y * v.y;
	w.z = u.z * v.z;
	return (w);
}

t_vector	div_vector(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.x / v.x;
	w.y = u.y / v.y;
	w.z = u.z / v.z;
	return (w);
}

t_vector	cross_prod(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}
