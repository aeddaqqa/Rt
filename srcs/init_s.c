/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:14:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/21 22:23:29 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_ocomponent			init_ocomponent(void)
{
	t_ocomponent		new;

	new.ambient = false;
	new.color = false;
	new.position = false;
	new.radius = false;
	new.orientation = false;
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

t_tags						init_tab_tags(void)
{
	t_tags tags;

	tags.elements_o[0] = (char*)"<plane>";
	tags.elements_o[1] = (char*)"<sphere>";
	tags.elements_o[2] = (char*)"<cylinder>";
	tags.elements_o[3] = (char*)"<cone>";
	tags.elements_o[4] = (char*)"<camera>";
	tags.elements_o[5] = (char*)"<light>";
	tags.elements_c[0] = (char*)"</plane>";
	tags.elements_c[1] = (char*)"</sphere>";
	tags.elements_c[2] = (char*)"</cylinder>";
	tags.elements_c[3] = (char*)"</cone>";
	tags.elements_c[4] = (char*)"</camera>";
	tags.elements_c[5] = (char*)"</light>";
	tags.components_o[0] = (char*)"<position>";
	tags.components_o[1] = (char*)"<color>";
	tags.components_o[2] = (char*)"<r_a>";
	tags.components_o[3] = (char*)"<ambient>";
	tags.components_o[4] = (char*)"<orientation>";
	tags.components_o[5] = (char*)"<look-at>";
	tags.components_o[6] = (char*)"<origin>";
	tags.components_o[7] = (char*)"<fov>";
	tags.components_o[8] = (char*)"<intensity>";
	tags.components_c[0] = (char*)"</position>";
	tags.components_c[1] = (char*)"</color>";
	tags.components_c[2] = (char*)"</r_a>";
	tags.components_c[3] = (char*)"</ambient>";
	tags.components_c[4] = (char*)"</orientation>";
	tags.components_c[5] = (char*)"</look-at>";
	tags.components_c[6] = (char*)"</origin>";
	tags.components_c[7] = (char*)"</fov>";
	tags.components_c[8] = (char*)"</intensity>";
	return (tags);
}
