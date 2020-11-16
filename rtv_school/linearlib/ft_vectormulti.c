/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectormulti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:53:24 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/07/01 02:59:49 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

t_vec		ft_vectormulti(t_vec c, float scalar)
{
	c.x *= scalar;
	c.y *= scalar;
	c.z *= scalar;
	return (c);
}
