/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:13:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/19 13:41:11 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_ray	*ray_init(t_rt *rt, double x, double y)
{
	t_ray		*new;
	double		px;
	double		py;
	t_vect3	tmp;
	t_vect3	tmp2;

	if (!(new = malloc(sizeof(t_ray))))
		destroy(MALLOC_ERROR);
	new->origin = rt->cameras->o;
	px = (2 * ((double)x + 0.5) / W) - 1;
	py = 1 - (2 * ((double)y + 0.5) / H);
	tmp = v_c_prod(rt->cameras->cords.u, px * rt->cameras->plan_w);
	tmp2 = v_c_prod(rt->cameras->cords.v, py * rt->cameras->plan_h);
	tmp = vect_add(tmp, tmp2);
	tmp = vect_add(tmp, rt->cameras->cords.w);
	new->direction = normalize(tmp);
	new->reflect_nb = 1;
	new->reflexion_index = 1.3;
	return (new);
}