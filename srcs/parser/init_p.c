/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:42:30 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:03:24 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_ocomponent			init_ocomponent(void)
{
	t_ocomponent		new;

	new.color = false;
	new.position = false;
	new.radius = false;
	new.angle = false;
	new.orientation = false;
	new.rotation = false;
	new.translation = false;
	new.height = false;
	new.dist = false;
	new.radius1 = false;
	new.radius2 = false;
	new.point_a = false;
	new.point_b = false;
	new.point_c = false;
	new.point_d = false;
	new.corner_a = false;
	new.corner_b = false;
	return (new);
}

static t_ccomponent			init_ccomponent(void)
{
	t_ccomponent		new;

	new.look_at = false;
	new.fov = false;
	new.origin = false;
	return (new);
}

static t_lcomponent			init_lcomponent(void)
{
	t_lcomponent		new;

	new.color = false;
	new.intensity = false;
	new.position = false;
	return (new);
}

t_node						init_node(void)
{
	t_node	new;

	new.type = -1;
	new.cmp = init_ocomponent();
	new.cam = init_ccomponent();
	new.lit = init_lcomponent();
	return (new);
}
