/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:38:51 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/23 13:24:00 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_rotate_hit(t_hit *hit, t_ray *save)
{
	hit->p = vec_add(save->source, vec_scale(save->direction, hit->t));
	ft_compute_normals(hit, save);
	hit->p = ft_rotate_object(hit->p, hit->object->rot, 0);
	hit->n = ft_rotate_object(hit->n, hit->object->rot, 0);
	hit->n = vec_norm(hit->n);
}

t_ray		ft_transform_ray(t_mlx *obj, t_ray *raw, int invert)
{
	t_ray	result;

	result = *raw;
	result.source = ft_rotate_object(raw->source, obj->rot, invert);
	result.direction = ft_rotate_object(raw->direction, obj->rot, invert);
	return (result);
}

void		ft_object1(t_mlx *p, t_raysave *z, t_hit *hit, float *t)
{
	if (p->id == 2)
	{
		if (hit_sphere(p, &z->ray, t))
			if (*t < hit->t)
			{
				hit->t = *t;
				hit->object = p;
				z->save = z->ray;
			}
	}
	else if (p->id == 3)
	{
		if (hit_cylinder(p, &z->ray, t))
			if (*t < hit->t)
			{
				hit->t = *t;
				hit->object = p;
				z->save = z->ray;
			}
	}
}

void		ft_object2(t_mlx *p, t_raysave *z, t_hit *hit, float *t)
{
	if (p->id == 4)
	{
		if (hit_cone(p, &z->ray, t))
			if (*t < hit->t)
			{
				hit->t = *t;
				hit->object = p;
				z->save = z->ray;
			}
	}
	else if (p->id == 5)
	{
		if (hit_plane(p, &z->ray, t))
			if (*t < hit->t)
			{
				hit->t = *t;
				hit->object = p;
				z->save = z->ray;
			}
	}
}

int			raycast(t_mlx *lst, t_ray *raw, t_hit *hit)
{
	t_mlx		*p;
	float		t;
	t_raysave	z;

	t = INFINITY;
	hit->object = NULL;
	p = lst;
	while (p)
	{
		if (p->id == 2 || p->id == 3 || p->id == 4 || p->id == 5)
		{
			z.ray = ft_transform_ray(p, raw, 1);
			if (p->id == 2 || p->id == 3)
				ft_object1(p, &z, hit, &t);
			else if (p->id == 4 || p->id == 5)
				ft_object2(p, &z, hit, &t);
		}
		p = p->next;
	}
	if (hit->object == NULL)
		return (0);
	ft_rotate_hit(hit, &z.save);
	return (1);
}
