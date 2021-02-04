/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:27 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/27 19:26:02 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		ft_sphere_normal(t_hit *hit)
{
	t_vect3	n;

	n = normalize(vect_sub(hit->p, hit->object->position));
	return (n);
}