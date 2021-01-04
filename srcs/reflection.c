/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:18:05 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/04 15:45:00 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_ray		*reflection(t_rt *rt, t_obj **obj, t_ray *ray, double t, int depth)
{
	t_obj			*tmp;
	t_obj			*close;
	t_ray			refl;
	t_ray			*ret;
	t_vector		n;
	double			x;

	t = -1;
	tmp = rt->objects;
	n = ray->obj_normal;
	refl.origin = ray->hit_point;
	refl.direction =\
//multip_vec_const((*obj)->normal, 2 * dot_prod(ray->hit_point, (*obj)->normal));
		multip_vec_const(n, 2 * dot_prod(ray->direction, n));
	refl.direction = normalize(sub_vector(ray->direction, refl.direction));
	ret = ray;
	while (tmp && (*obj)->type == PLANE)
	{
		if (tmp != *obj)
			x = rt->hit_object[tmp->type](tmp, &refl);
		if (tmp != *obj && x != -1 && (x < t || t == -1))
		{
			close = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
	{
		if (close->type < 2 && depth)
		{
			refl.hit_point =\
    		add_vector(refl.origin, multip_vec_const(refl.direction, t));
			ret = &refl;
			obj_normal(close, &ret, t);
			ret = &refl;
			if (close->type == PLANE)
				return reflection(rt, &close, ret, t, depth - 1);
			if (close->type == SPHERE)
				return refraction(rt, &close, ret, t, depth - 1);
		}
		else
		{
		//	*obj = close;
			ret = malloc(sizeof(t_ray));
			ret->origin = refl.origin;
			ret->direction = refl.direction;
			ret->hit_point = refl.hit_point;
			obj_normal(close, &ret, t);
			return (ret);
		}
	}
	return (ray);
}

void	refract(t_rt *rt, t_obj *obj, t_ray *ray, double n)
{
	double			c1, c2, x;
	t_vector		nr;

	x = -1 * rt->hit_object[obj->type](obj, ray);
	obj_normal(obj, &ray, x);
	nr = multip_vec_const(ray->obj_normal, -1.0);
	ray->hit_point =\
    		add_vector(ray->origin, multip_vec_const(ray->direction, x));
	//n = 1 / n;
	c1 = dot_prod(nr, ray->direction);
	c2 = sqrtf(1 - n * n * (1 - c1 * c1));
	ray->direction = multip_vec_const(ray->direction, n);
	ray->direction =\
		add_vector(ray->direction, multip_vec_const(nr,  n * c1 - c2));
	ray->direction = normalize(ray->direction);
}

t_ray		*refraction(t_rt *rt, t_obj **obj, t_ray *ray, double t, int depth)
{
	t_obj			*tmp;
	t_ray			refra;
	t_obj			*close;
	t_ray			*ret;
	double			c1, c2, n, x;

	t = -1;
	n = 1 / 1.517;
	c1 = dot_prod(ray->obj_normal, ray->direction);
	if (c1 < 0)
		c1 *= -1;
	c2 = sqrtf(1 - n * n * (1 - powf(c1, 2)));
	refra.direction = multip_vec_const(ray->direction, n);
	refra.direction =\
		add_vector(refra.direction, multip_vec_const(ray->obj_normal, n * c2 - c1));
	tmp = rt->objects;
	refra.origin = ray->hit_point;
//	refra.direction = multip_vec_const(refra.direction, -1.0);
	refra.direction = normalize(refra.direction);
//	refract(rt, *obj, &refra, n);
	while (tmp && (*obj)->type == SPHERE)
	{
		if (tmp != *obj)
			x = rt->hit_object[tmp->type](tmp, &refra);
		if (tmp != *obj && x != -1 && (x < t || t == -1))
		{
			close = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
	{
		if (depth && close->type < 2)
		{
			refra.hit_point =\
    		add_vector(refra.origin, multip_vec_const(refra.direction, t));
			ret = &refra;
			obj_normal(close, &ret, t);
			ret = &refra;
			if (close->type == PLANE)
				return reflection(rt, &close, ret, t, depth - 1);
			if (close->type == SPHERE)
				return refraction(rt, &close, ret, t, depth - 1);
		}
		else
		{
		//	*obj = close;
			ret = malloc(sizeof(t_ray));
			ret->origin = refra.origin;
			ret->direction = refra.direction;
			ret->hit_point = refra.hit_point;
			obj_normal(close, &ret, t);
			return (ret);
		}
	}

	return (ray);
}
