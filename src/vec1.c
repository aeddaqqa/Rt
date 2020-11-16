/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:59 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/14 17:40:02 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		vec_add(t_vec vec1, t_vec vec2)
{
	t_vec vec;

	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}

t_vec		vec_sub(t_vec vec1, t_vec vec2)
{
	t_vec vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
}

float		vec_dot(t_vec vec1, t_vec vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vec		vec_cross(t_vec vec1, t_vec vec2)
{
	t_vec vec;

	vec.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	vec.y = (vec2.x * vec1.z) - (vec1.x * vec2.z);
	vec.z = (vec1.x * vec2.y) - (vec2.x * vec1.y);
	return (vec);
}
