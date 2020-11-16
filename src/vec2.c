/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:40:10 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/16 10:00:22 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		vec_scale(t_vec vec1, float scale)
{
	t_vec vec;

	vec.x = vec1.x * scale;
	vec.y = vec1.y * scale;
	vec.z = vec1.z * scale;
	return (vec);
}

float		vec_len(t_vec vec1)
{
	return (sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z)));
}

t_vec		vec_norm(t_vec vec1)
{
	return (vec_scale(vec1, 1.0 / vec_len(vec1)));
}
