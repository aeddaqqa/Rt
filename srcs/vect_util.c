/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:54:37 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/07 05:40:12 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	addvec_const(t_vector u, double v)
{
	t_vector	w;

	w.x = u.x + v;
	w.y = u.y + v;
	w.z = u.z + v;
	return (w);
}

t_vector	subvec_const(t_vector u, double v)
{
	t_vector	w;

	w.x = u.x - v;
	w.y = u.y - v;
	w.z = u.z - v;
	return (w);
}

t_vector	multip_vec_const(t_vector u, double v)
{
	t_vector	w;

	w.x = u.x * v;
	w.y = u.y * v;
	w.z = u.z * v;
	return (w);
}

double		dot_prod(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	normalize(t_vector vec)
{
	double	mod;

	mod = sqrtf(dot_prod(vec, vec));
	return ((t_vector){vec.x / mod, vec.y / mod, vec.z / mod});
}
