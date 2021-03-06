/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:27:35 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/05 18:27:36 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	normalize(t_vect3 vec)
{
	double	mod;

	mod = sqrtf(dot(vec, vec));
	return ((t_vect3){vec.x / mod, vec.y / mod, vec.z / mod});
}
