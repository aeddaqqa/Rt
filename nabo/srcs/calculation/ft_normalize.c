/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:53:01 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/01/27 15:42:59 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	normalize(t_vect3 vec)
{
	double	mod;

	mod = sqrtf(dot(vec, vec));
	return ((t_vect3){vec.x / mod, vec.y / mod, vec.z / mod});
}
