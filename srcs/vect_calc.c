/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:19:05 by farwila           #+#    #+#             */
/*   Updated: 2021/01/04 23:20:44 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../includes/rt.h"

t_vect3	add_vector(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vect3	sub_vector(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vect3	multip_vector(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.x * v.x;
	w.y = u.y * v.y;
	w.z = u.z * v.z;
	return (w);
}

t_vect3	div_vector(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.x / v.x;
	w.y = u.y / v.y;
	w.z = u.z / v.z;
	return (w);
}

t_vect3	cross_prod(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

t_vect3	addvec_const(t_vect3 u, double v)
{
	t_vect3	w;

	w.x = u.x + v;
	w.y = u.y + v;
	w.z = u.z + v;
	return (w);
}

t_vect3	subvec_const(t_vect3 u, double v)
{
	t_vect3	w;

	w.x = u.x - v;
	w.y = u.y - v;
	w.z = u.z - v;
	return (w);
}

t_vect3	multip_vec_const(t_vect3 u, double v)
{
	t_vect3	w;

	w.x = u.x * v;
	w.y = u.y * v;
	w.z = u.z * v;
	return (w);
}

double		dot_prod(t_vect3 u, t_vect3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vect3	normalize(t_vect3 vec)
{
	double	mod;

	mod = sqrtf(dot_prod(vec, vec));
	return ((t_vect3){vec.x / mod, vec.y / mod, vec.z / mod});
}