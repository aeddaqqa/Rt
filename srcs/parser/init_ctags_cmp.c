/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctags_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:21:05 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:41:02 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

/*
********************************************************
*/

void			init_ctags_cmp_follow_up(t_tags *tags)
{
	tags->components_c[DISTANCE] = (char*)"</distance>";
	tags->components_c[RADIUS_1] = (char*)"</radius_1>";
	tags->components_c[RADIUS_2] = (char*)"</radius_2>";
	tags->components_c[POINT_A] = (char*)"</point_a>";
	tags->components_c[POINT_B] = (char*)"</point_b>";
	tags->components_c[POINT_C] = (char*)"</point_c>";
	tags->components_c[POINT_D] = (char*)"</point_d>";
	tags->components_c[CORNER_A] = (char*)"</corner_a>";
	tags->components_c[CORNER_B] = (char*)"</corner_b>";
	tags->components_c[REFLEXION] = (char*)"</reflexion>";
	tags->components_c[TRANSPARENT] = (char*)"</transparent>";
	tags->components_c[REF_INDEX] = (char*)"</ref_index>";
	tags->components_c[MATTER] = (char*)"</matter>";
	tags->components_c[TEXTURE] = (char*)"</texture>";
	tags->components_c[SLICE] = (char*)"</slice>";
	tags->components_c[LIGHT_TYPE] = (char*)"</type>";
}

/*
********************************************************
*/

void			init_ctags_cmp(t_tags *tags)
{
	tags->components_c[POSITION] = (char*)"</position>";
	tags->components_c[COLOR] = (char*)"</color>";
	tags->components_c[ANGLE] = (char*)"</angle>";
	tags->components_c[RADIUS] = (char*)"</radius>";
	tags->components_c[TRANSLATION] = (char*)"</translation>";
	tags->components_c[ROTATION] = (char*)"</rotation>";
	tags->components_c[ORIENTATION] = (char*)"</orientation>";
	tags->components_c[LOOK_AT] = (char*)"</look-at>";
	tags->components_c[ORIGIN] = (char*)"</origin>";
	tags->components_c[FOV] = (char*)"</fov>";
	tags->components_c[INTENSITY] = (char*)"</intensity>";
	tags->components_c[HEIGHT] = (char*)"</height>";
	init_ctags_cmp_follow_up(tags);
}
