/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_const_prod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:26:59 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/05 18:27:01 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		v_c_prod(t_vect3 c, double scalar)
{
	c.x *= scalar;
	c.y *= scalar;
	c.z *= scalar;
	return (c);
}
