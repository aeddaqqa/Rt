/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:28:26 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/27 19:17:48 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		ft_cone_normal(t_object *cone, t_vect3 p)
{
	p = v_c_prod(p, 1.0 / cone->angle);
	return (ft_vector(p.x, 0.001, p.z));
}
