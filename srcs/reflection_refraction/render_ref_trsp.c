/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ref_trsp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:29:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/21 09:37:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_ray ref_intersect(t_object *p, t_hit *hit, t_ray ray, t_object *node)
{
	t_ray save;
	double t;

	t = INFINITY;
	while (p)
	{
		if (p != node && p->type == SPHERE)
			ft_sphere_intersect(p, &ray, &t);
		else if (p != node && p->type == PLANE)
			ft_plane_intersect(p, &ray, &t);
		else if (p != node && p->type == CYLINDER)
			ft_cylinder_intersect(p, &ray, &t);
		else if (p != node && p->type == CONE)
			ft_cone_intersect(p, &ray, &t);
		else if (p != node && p->type == BOX)
			box_intersect(p, &ray, &t);
		else if (p != node && p->type == PARALLELOGRAM)
			ft_parallelogram_intersect(p, &ray, &t);
		if (hit->t > t && t > 0)
		{
			hit->t = t;
			hit->object = p;
			save = ray;
		}
		p = p->next;
	}
	if (hit->object)
	{
		hit->p = vect_add(save.origin, v_c_prod(save.direction, hit->t));
		ft_compute_normals(hit, &save);
	}
	return (save);
}

t_color ref_trsp(t_rt *rt, t_hit hit, t_ray reflect, t_light *light)
{
	t_hit	hit1;

	hit1.t = INFINITY;
	hit1.object = NULL;
	ref_intersect(rt->objects, &hit1, reflect, hit.object);
	if (hit1.object)
	{
		return (lit_comp(light, &hit1, &reflect));
	}
	return ((t_color){0, 0, 0});
}