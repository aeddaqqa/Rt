/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:33 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/28 08:50:29 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color			ambient(t_object *obj, double amb)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, amb);
	color = vect_prod(color, obj->color);
	return (color);
}