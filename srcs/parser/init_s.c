/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:14:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/22 15:54:05 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static	void			init_otags_elements(t_tags *tags)
{
	tags->elements_o[PLANE] = (char*)"<plane>";
	tags->elements_o[SPHERE] = (char*)"<sphere>";
	tags->elements_o[CYLINDER] = (char*)"<cylinder>";
	tags->elements_o[CONE] = (char*)"<cone>";
	tags->elements_o[CAMERA] = (char*)"<camera>";
	tags->elements_o[LIGHT] = (char*)"<light>";
	tags->elements_o[ELLIPSOID] = (char*)"<ellipsoid>";
	tags->elements_o[PARABOLOID] = (char*)"<paraboloid>";
	tags->elements_o[TRIANGLE] = (char*)"<triangle>";
	tags->elements_o[BOX] = (char*)"<box>";
	tags->elements_o[PARALLELOGRAM] = (char*)"<parallelogram>";
	tags->elements_o[TORUS] = (char*)"<torus>";
	tags->elements_o[DISK] = (char*)"<disk>";
	tags->elements_o[AMBIENT] = (char*)"<ambient>";
}

static	void			init_ctags_elements(t_tags *tags)
{
	tags->elements_c[PLANE] = (char*)"</plane>";
	tags->elements_c[SPHERE] = (char*)"</sphere>";
	tags->elements_c[CYLINDER] = (char*)"</cylinder>";
	tags->elements_c[CONE] = (char*)"</cone>";
	tags->elements_c[CAMERA] = (char*)"</camera>";
	tags->elements_c[LIGHT] = (char*)"</light>";
	tags->elements_c[ELLIPSOID] = (char*)"</ellipsoid>";
	tags->elements_c[PARABOLOID] = (char*)"</paraboloid>";
	tags->elements_c[TRIANGLE] = (char*)"</triangle>";
	tags->elements_c[BOX] = (char*)"</box>";
	tags->elements_c[PARALLELOGRAM] = (char*)"</parallelogram>";
	tags->elements_c[TORUS] = (char*)"</torus>";
	tags->elements_c[DISK] = (char*)"</disk>";
	tags->elements_c[AMBIENT] = (char*)"</ambient>";
}

static	void			init_otags_cmp(t_tags *tags)
{
	tags->components_o[POSITION] = (char*)"<position>";
	tags->components_o[COLOR] = (char*)"<color>";
	tags->components_o[ANGLE] = (char*)"<angle>";
	tags->components_o[RADIUS] = (char*)"<radius>";
	tags->components_o[TRANSLATION] = (char*)"<translation>";
	tags->components_o[ROTATION] = (char*)"<rotation>";
	tags->components_o[ORIENTATION] = (char*)"<orientation>";
	tags->components_o[LOOK_AT] = (char*)"<look-at>";
	tags->components_o[ORIGIN] = (char*)"<origin>";
	tags->components_o[FOV] = (char*)"<fov>";
	tags->components_o[INTENSITY] = (char*)"<intensity>";
	tags->components_o[HEIGHT] = (char*)"<height>";
	tags->components_o[DISTANCE] = (char*)"<distance>";
	tags->components_o[RADIUS_1] = (char*)"<radius_1>";
	tags->components_o[RADIUS_2] = (char*)"<radius_2>";
	tags->components_o[POINT_A] = (char*)"<point_a>";
	tags->components_o[POINT_B] = (char*)"<point_b>";
	tags->components_o[POINT_C] = (char*)"<point_c>";
	tags->components_o[POINT_D] = (char*)"<point_d>";
	tags->components_o[CORNER_A] = (char*)"<corner_a>";
	tags->components_o[CORNER_B] = (char*)"<corner_b>";
}

static	void			init_ctags_cmp(t_tags *tags)
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
	tags->components_c[DISTANCE] = (char*)"</distance>";
	tags->components_c[RADIUS_1] = (char*)"</radius_1>";
	tags->components_c[RADIUS_2] = (char*)"</radius_2>";
	tags->components_c[POINT_A] = (char*)"</point_a>";
	tags->components_c[POINT_B] = (char*)"</point_b>";
	tags->components_c[POINT_C] = (char*)"</point_c>";
	tags->components_c[POINT_D] = (char*)"</point_d>";
	tags->components_c[CORNER_A] = (char*)"</corner_a>";
	tags->components_c[CORNER_B] = (char*)"</corner_b>";
}

t_tags					init_tab_tags(void)
{
	t_tags tags;

	init_otags_elements(&tags);
	init_ctags_elements(&tags);
	init_otags_cmp(&tags);
	init_ctags_cmp(&tags);
	return (tags);
}
