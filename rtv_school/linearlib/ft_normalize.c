/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:53:01 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/18 20:03:30 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

t_vec		ft_normalize(t_vec v)
{
	float	magnitude;

	magnitude = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= magnitude;
	v.y /= magnitude;
	v.z /= magnitude;
	return (v);
}
