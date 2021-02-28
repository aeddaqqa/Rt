/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:42:30 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/28 11:25:30 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_rt						*init_rt(bool save)
{
	t_rt	*new;

	if (!(new = malloc(sizeof(t_rt))))
		return (NULL);
	new->save = save;
	new->cameras = NULL;
	new->lights = NULL;
	new->objects = NULL;
	new->ambient = 0;
	new->nbr_lights = 0;
	new->ambient_exist = false;
	new->intersection = malloc(sizeof(double (*)(t_object*, t_ray*)) * 13);
	new->normal = malloc(sizeof(t_vect3 (*)(t_object*, t_ray*)) * 13);
	new->intersection[0] = hit_plane;
	new->intersection[1] = hit_sphere;
	new->intersection[2] = hit_cylinder;
	new->intersection[3] = hit_cone;
	new->intersection[4] = NULL;
	new->intersection[5] = NULL;
	new->intersection[6] = hit_ellipsoid;
	new->intersection[7] = hit_paraboloid;
	new->intersection[8] = hit_triangle;
	new->intersection[9] = hit_box;
	new->intersection[10] = hit_parallelogram;
	new->intersection[11] = NULL;
	new->intersection[12] = hit_disk;
	new->normal[0] = plane_normal;
	new->normal[1] = sphere_normal;
	new->normal[2] = cylinder_normal;
	new->normal[3] = cone_normal;
	new->normal[4] = NULL;
	new->normal[5] = NULL;
	new->normal[6] = ellipsoid_normal;
	new->normal[7] = paraboloid_normal;
	new->normal[8] = triangle_normal;
	new->normal[9] = box_normal;
	new->normal[10] = normal_parallelogram;
	new->normal[11] = NULL;
	new->normal[12] = normal_disk;
	return (new);
}

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
