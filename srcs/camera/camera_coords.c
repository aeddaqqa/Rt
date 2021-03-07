/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:33:59 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/07 11:36:11 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			checkvec(t_vect3 fwd, t_vect3 vup)
{
	float	chk;

	chk = dot(fwd, vup);
	if ((chk > 0.8 && chk <= 1) || (chk < -0.8 && chk >= -1))
		return ((t_vect3){1, 0, 0});
	return ((t_vect3){0, 1, 0});
}

void			new_camera(t_rt *rt)
{
	t_vect3 tmp;

	rt->cameras->o.z += 0.0005;
	rt->cameras->ratio = (double)(W / H);
	rt->cameras->plan_h = tan(rt->cameras->fov / 2);
	rt->cameras->plan_w = rt->cameras->plan_h * rt->cameras->ratio;
	tmp = vect_sub(rt->cameras->l, rt->cameras->o);
	rt->cameras->cords.w = normalize(tmp);
	tmp = cross(rt->cameras->cords.w, rt->cameras->up);
	rt->cameras->cords.u = normalize(tmp);
	rt->cameras->cords.v = cross(rt->cameras->cords.u, rt->cameras->cords.w);
}
