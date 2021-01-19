/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:14:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/19 18:39:05 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_ocomponent			init_ocomponent(void)
{
	t_ocomponent		new;

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

	tags.elements_o[PLANE_O] = (char*)"<plane>";
	tags.elements_o[SPHERE_O] = (char*)"<sphere>";
	tags.elements_o[CYLINDER_O] = (char*)"<cylinder>";
	tags.elements_o[CONE_O] = (char*)"<cone>";
	tags.elements_o[CAMERA_O] = (char*)"<camera>";
	tags.elements_o[LIGHT_O] = (char*)"<light>";
	tags.elements_c[PLANE_C] = (char*)"</plane>";
	tags.elements_c[SPHERE_C] = (char*)"</sphere>";
	tags.elements_c[CYLINDER_C] = (char*)"</cylinder>";
	tags.elements_c[CONE_C] = (char*)"</cone>";
	tags.elements_c[CAMERA_C] = (char*)"</camera>";
	tags.elements_c[LIGHT_C] = (char*)"</light>";
	
	tags.components_o[POSITION] = (char*)"<position>";
	tags.components_o[COLOR] = (char*)"<color>";
	tags.components_o[R_A] = (char*)"<r_a>";
	tags.components_o[ORIENTATION] = (char*)"<orientation>";
	tags.components_o[LOOK_AT] = (char*)"<look-at>";
	tags.components_o[ORIGIN] = (char*)"<origin>";
	tags.components_o[FOV] = (char*)"<fov>";
	tags.components_o[INTENSITY] = (char*)"<intensity>";
	
	tags.components_c[POSITION] = (char*)"</position>";
	tags.components_c[COLOR] = (char*)"</color>";
	tags.components_c[R_A] = (char*)"</r_a>";
	tags.components_c[ORIENTATION] = (char*)"</orientation>";
	tags.components_c[LOOK_AT] = (char*)"</look-at>";
	tags.components_c[ORIGIN] = (char*)"</origin>";
	tags.components_c[FOV] = (char*)"</fov>";
	tags.components_c[INTENSITY] = (char*)"</intensity>";
	return (tags);
}
