/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:52:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/01/27 18:56:29 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		ft_magnitude(t_vect3 v)
{
	t_vect3	c;

	c.x = v.x * v.x;
	c.y = v.y * v.y;
	c.z = v.z * v.z;
	return (sqrt(c.x + c.y + c.z));
}
