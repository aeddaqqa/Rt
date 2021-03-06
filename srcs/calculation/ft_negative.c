/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:52:49 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/01/27 18:53:16 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		ft_negative(t_vect3 v)
{
	t_vect3	c;

	c.x = -1.0 * v.x;
	c.y = -1.0 * v.y;
	c.z = -1.0 * v.z;
	return (c);
}
