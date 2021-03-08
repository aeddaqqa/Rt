/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_matter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:50:31 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/08 13:05:03 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	set_matter(t_object *o)
{
	if (o->matter == GLASS)
	{
		o->refraction_index = 1.5;
		o->is_transp = 0.9;
		o->is_ref = 0.1;
		o->color = (t_color){246.0 / 255, 254.0 / 255, 1.0};
	}
	if (o->matter == WATER)
	{
		o->refraction_index = 1.3;
		o->is_transp = 0.6;
		o->is_ref = 0.2;
		o->color = (t_color){212.0 / 255, 241.0 / 255, 249.0 / 255};
	}
	if (o->matter == DIAMOND)
	{
		o->refraction_index = 1.8;
		o->is_transp = 0.9;
		o->is_ref = 0.4;
		o->color = (t_color){185.0 / 255, 242.0 / 255, 1.0};
	}
}
