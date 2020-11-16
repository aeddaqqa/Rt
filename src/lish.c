/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:38:03 by chzabakh          #+#    #+#             */
/*   Updated: 2020/11/07 09:37:44 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ndcheck(t_mlx *p, t_ray *ray, float *t, float *tmin)
{
	if (p->id == 3)
		if (hit_cylinder(p, ray, t))
			if (*t < *tmin)
				return (1);
	if (p->id == 4)
		if (hit_cone(p, ray, t))
			if (*t < *tmin)
				return (1);
	if (p->id == 5)
		if (hit_plane(p, ray, t))
			if (*t < *tmin)
				return (1);
	return (0);
}

t_vec	lit_comp(t_mlx *light, t_vec light_dir, t_hit *hit, t_ray *ray)
{
	float		lambert;
	t_vec		color;
	float		reflect;
	float		phong_term;
	t_vec		phong_dir;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	color.x = 0.05 * light->clr.x * hit->object->clr.x;
	color.y = 0.05 * light->clr.y * hit->object->clr.y;
	color.z = 0.05 * light->clr.z * hit->object->clr.z;
	lambert = fmax(0.0f, vec_dot(light_dir, hit->n));
	color = vec_add(color, vec_scale(hit->object->clr, lambert));
	reflect = 2.0f * (vec_dot(light_dir, hit->n));
	phong_dir = vec_sub(light_dir, vec_scale(hit->n, reflect));
	phong_term = fmax(vec_dot(phong_dir, ray->direction), 0.0f);
	phong_term = 1.0f * powf(phong_term, 90.0f) * 1.0f;
	color = vec_add(color, vec_scale(light->clr, phong_term));
	color.x = color.x * light->clr.x * light->ntnst / 10;
	color.y = color.y * light->clr.y * light->ntnst / 10;
	color.z = color.z * light->clr.z * light->ntnst / 10;
	return (color);
}

int		shadow_cast(t_mlx *lst, t_ray *raay, float *tmin)
{
	t_mlx	*p;
	float	t;
	t_ray	ray;

	t = INFINITY;
	p = lst;
	while (p)
	{
		if (p->id == 2 || p->id == 3 || p->id == 4 || p->id == 5)
		{
			ray = ft_transform_ray(p, raay, 1);
			if (p->id == 2)
				if (hit_sphere(p, &ray, &t))
					if (t < *tmin)
						return (1);
			if (p->id == 3 || p->id == 4 || p->id == 5)
				if (ndcheck(p, &ray, &t, tmin))
					return (1);
		}
		p = p->next;
	}
	return (0);
}

int		ft_shade(t_hit *hit, t_mlx *lights, t_mlx *hd, t_ray *ray)
{
	t_mlx	*lits;
	t_vec	color;
	t_vec	light_dir;
	t_ray	shadow_ray;
	float	t;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	shadow_ray.source = hit->p;
	lits = lights;
	while (lits)
	{
		if (lits->id == 1)
		{
			light_dir = vec_norm(vec_sub(lits->pos, hit->p));
			shadow_ray.direction = light_dir;
			t = vec_len(vec_sub(lits->pos, hit->p));
			if (!shadow_cast(hd, &shadow_ray, &t))
				color = vec_add(color, lit_comp(lits, \
							light_dir, hit, ray));
			else
				color = amb(color, lits->clr, hit->object->clr);
		}
		lits = lits->next;
	}
	return (rgb_to_int(clamp_vec(color)));
}
