/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:11 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/27 09:32:17 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		ft_min_ray(float t1, float t2, float *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
}

int sphere_intersect(t_object *sphere, t_ray *ray, float *tmin)
{
	t_vec x;
	float a, b, c, delta;
	float t1, t2;
	float t;
	
	t = INFINITY;
	x = ft_vectorsub(ray->source, sphere->pos);
	a = ft_dotproduct(ray->direction, ray->direction);
	b = 2.0 * ft_dotproduct(ray->direction, x);
	c = ft_dotproduct(x, x) - sphere->radius * sphere->radius;
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0)
		return (0);
	delta = sqrtf(delta);
	t1 = (-b + delta) / (2 * a);
	t2 = (-b - delta) / (2 * a);
	return (ft_min_ray(t1, t2, tmin));
}

int		plane_intersect(t_object *plane, t_ray *ray, float *tmin)
{
	t_vec	x;
	float	a;
	float	b;
	float	t;
	float	t1;

	t = INFINITY;
	x = ft_vectorsub(ray->source, plane->pos);
	a = -1.0 * ft_dotproduct(x, plane->normal);
	b = ft_dotproduct(ray->direction, plane->normal);
	if (fabs(b) <= 1e-6)
		return (0);
	t1 = a / b;
	if (t1 > 1e-2 && t1 < *tmin)
	{
		*tmin = t1;
		return (1);
	}
	return (0);
}

int		cylinder_intersect(t_object *cylinder, t_ray *ray, float *tmin)
{
	t_vec	x;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t;
	float	t1;
	float	t2;

	t = INFINITY;
	x = ft_vectorsub(ray->source, cylinder->pos);
	a = ft_dotproduct(ray->direction, ray->direction) - powf(ft_dotproduct(ray->direction, cylinder->axis), 2.0);
	b = 2.0 * (ft_dotproduct(ray->direction, x) - (ft_dotproduct(ray->direction, cylinder->axis) * ft_dotproduct(x, cylinder->axis)));
	c = ft_dotproduct(x, x) - powf(ft_dotproduct(x, cylinder->axis), 2.0) - (cylinder->radius * cylinder->radius);
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0)
		return (0);
	delta = sqrtf(delta);
	t1 = (-b + delta) / (2 * a);
	t2 = (-b - delta) / (2 * a);
	return (ft_min_ray(t1, t2, tmin));
}

int		cone_intersect(t_object *cone, t_ray *ray, float *tmin)
{
	t_vec	x;
	float	k;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t;
	float	t1;
	float	t2;

	t = INFINITY;
	x = ft_vectorsub(ray->source, cone->pos);
	k = tanf(deg_to_rad(cone->angle) / 2.0);
	a = ft_dotproduct(ray->direction, ray->direction) - (1.0 + (k * k)) * powf(ft_dotproduct(ray->direction, cone->axis), 2.0);
	b = 2.0 * (ft_dotproduct(ray->direction, x) - ((1.0 + (k * k)) * ft_dotproduct(ray->direction, cone->axis) * ft_dotproduct(x, cone->axis)));
	c = ft_dotproduct(x, x) - (1.0 + (k * k)) * powf(ft_dotproduct(x, cone->axis), 2.0);
	delta = (b * b) - (4.0 * a * c);
	if (delta < 0)
		return (0);
	delta = sqrtf(delta);
	t1 = (-b + delta) / (2 * a);
	t2 = (-b - delta) / (2 * a);
	return (ft_min_ray(t1, t2, tmin));
}

void	ft_compute_normals(t_hit *hit, t_ray *ray)
{
	//(void)ray;
	t_vec	x;
	float	m;
	float	k;
	//float	a;
	
	if (hit->object->type == SPHERE)
		hit->n = ft_normalize(ft_vectorsub(hit->p, hit->object->pos));
	else if (hit->object->type == PLANE)
		hit->n = hit->object->normal;
	else if (hit->object->type == CYLINDER)
	{
		x = ft_vectorsub(ray->source, hit->object->pos);
		m = ft_dotproduct(ray->direction, ft_vectormulti(hit->object->axis, hit->t)) + ft_dotproduct(x, hit->object->axis);
		hit->n = ft_normalize(ft_vectorsub(ft_vectorsub(hit->p, hit->object->pos), ft_vectormulti(hit->object->axis, m)));
	}
	else if (hit->object->type == CONE)
	{
		x = ft_vectorsub(ray->source, hit->object->pos);
		m = ft_dotproduct(ray->direction, ft_vectormulti(hit->object->axis, hit->t)) + ft_dotproduct(x, hit->object->axis);
		k = tanf(deg_to_rad(hit->object->angle) / 2.0);
		//a = m * k * k;
		hit->n = ft_normalize(ft_vectorsub(ft_vectorsub(hit->p, hit->object->pos), ft_vectormulti(hit->object->axis, ((1.0 + (k * k)) * m))));
	}
}

t_vec	ft_light_computing(t_light *light, t_vec light_dir, t_hit *hit, t_ray *ray)
{
	float 		lambert;
	float		ambient_strenght;
	t_vec		ambient;
	t_vec		color;
	float		reflect;
	float		phong_term;
	t_vec		phong_dir;
	// t_vec		blinn_dir;
	// float		temp;
	// float		blinn_term;

	// this is the ambient calculation;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	ambient_strenght = 0.05f;
	ambient = ft_vectormulti(light->color, ambient_strenght);
	color.x = ambient.x * hit->object->color.x;
	color.y = ambient.y * hit->object->color.y;
	color.z = ambient.z * hit->object->color.z;

	// the following is the diffuse calculation;

	//color = (t_vec){0.0f, 0.0f, 0.0f};
	lambert = fmax(0.0f, ft_dotproduct(light_dir, hit->n));
	color = ft_vectoradd(color, ft_vectormulti(hit->object->color, lambert));

	// and this is the calculation of the shininess of the object (specular) using Bui Tuong Phong shading methode;

	reflect = 2.0f * (ft_dotproduct(light_dir, hit->n));
	phong_dir = ft_vectorsub(light_dir, ft_vectormulti(hit->n, reflect));
	phong_term = fmax(ft_dotproduct(phong_dir, ray->direction), 0.0f);
	phong_term = 1.0f * powf(phong_term, 90.0f) * 1.0f;
	color = ft_vectoradd(color, ft_vectormulti(light->color, phong_term));
	
	// and this is the calculation of the shininess of the object (specular) using Jim Blinn shading way;

	/*blinn_dir = ft_vectorsub(light_dir, ray->direction);
	temp = sqrtf(ft_dotproduct(blinn_dir, blinn_dir));
	if (temp != 0.0f)
	{
		blinn_dir = ft_vectormulti(blinn_dir, (1.0f / temp));
		blinn_term = fmax(ft_dotproduct(blinn_dir, hit->n), 0.0f);
		blinn_term = 1.0f * powf(blinn_term, 90.0f) * 1.0f;
		color = ft_vectoradd(color, ft_vectormulti(hit->object->color, blinn_term));
	}*/

	//printf("Intensity : %.10f\n", light->intensity);
	color.x = color.x * light->color.x * light->intensity;
	color.y = color.y * light->color.y * light->intensity;
	color.z = color.z * light->color.z * light->intensity;
	return (color);
}

int 	ft_shade_object(t_hit *hit, t_light *lights, t_object *lst, t_ray *ray)
{
	t_light 	*light;
	t_vec		color;
	t_vec		light_dir;
	t_ray		shadow_ray;

	float t;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	shadow_ray.source = hit->p;
	light = lights;
	while (light)
	{
		light_dir = ft_normalize(ft_vectorsub(light->pos, hit->p));
		shadow_ray.direction = light_dir;
		t = ft_magnitude(ft_vectorsub(light->pos, hit->p));
		if (!shadow_cast(lst, &shadow_ray, &t))
			color = ft_vectoradd(color, ft_light_computing(light, light_dir, hit, ray));
		light = light->next;
	}
	return (rgb_to_int(clamp_vect(color)));
}

t_vec	ft_rotate_object(t_vec to_rot, t_vec rot, int invert)
{
	if (invert)
	{
		to_rot = z_rotation(to_rot, -rot.z);
		to_rot = y_rotation(to_rot, -rot.y);
		// result = z_rotation(to_rot, -rot.z);
		// result = y_rotation(to_rot, -rot.y);
		// result = x_rotation(to_rot, -rot.x);
		to_rot = x_rotation(to_rot, -rot.x);
	}
	else
	{
		to_rot = x_rotation(to_rot, rot.x);
		to_rot = y_rotation(to_rot, rot.y);
		// result = x_rotation(to_rot, rot.x);
		// result = y_rotation(to_rot, rot.y);
		// result = z_rotation(to_rot, rot.z);
		to_rot = z_rotation(to_rot, rot.z);
	}
	return (to_rot);
}

t_vec	ft_translate_object(t_vec to_trans, t_vec trans, int invert)
{
	t_vec	result;

	if (invert)
	{
		result.x = to_trans.x - trans.x;
		result.y = to_trans.y - trans.y;
		result.z = to_trans.z - trans.z;
	}
	else
	{
		result.x = to_trans.x + trans.x;
		result.y = to_trans.y + trans.y;
		result.z = to_trans.z + trans.z;
	}
	return (result);
}

t_ray	ft_transform_ray(t_object *obj, t_ray *raw, int invert)
{
	t_ray	result;

	result = *raw;
	result.source = ft_rotate_object(raw->source, obj->rot, invert);
	result.source = ft_translate_object(result.source, obj->trans, invert);
	result.direction = ft_rotate_object(raw->direction, obj->rot, invert);
	return (result);
}

int		raycast(t_object *lst, t_ray *raw, t_hit *hit)
{
	t_object	*p;
	float		t;
	t_ray		ray;
	t_ray		save;

	t = INFINITY;
	hit->object = NULL;
	hit->t = INFINITY;
	p = lst;
	while (p)
	{
		ray = ft_transform_ray(p, raw, 1);
		if (p->type == SPHERE)
		{
			if (sphere_intersect(p, &ray, &t))
				if (hit->t > t)
				{
					hit->t = t;
					hit->object = p;
					save = ray;
				}
		}
		else if (p->type == PLANE)
		{
			if (plane_intersect(p, &ray, &t))
				if (hit->t > t)
				{
					hit->t = t;
					hit->object = p;
					save = ray;
				}
		}
		else if (p->type == CYLINDER)
		{
			if (cylinder_intersect(p, &ray, &t))
				if (hit->t > t)
				{
					hit->t = t;
					hit->object = p;
					save = ray;
				}
		}
		else if (p->type == CONE)
		{
			if (cone_intersect(p, &ray, &t))
				if (hit->t > t)
				{
					hit->t = t;
					hit->object = p;
					save = ray;
				}
		}
		p = p->next;
	}
	if (hit->object == NULL)
		return (0);
	hit->p = ft_vectoradd(save.source, ft_vectormulti(save.direction, hit->t));
	ft_compute_normals(hit, &save);
	hit->p = ft_translate_object(hit->p, hit->object->trans, 0);
	hit->p = ft_rotate_object(hit->p, hit->object->rot, 0);
	hit->n = ft_rotate_object(hit->n, hit->object->rot, 0);
	hit->n = ft_normalize(hit->n);
	return (1);
}

int 	shadow_cast(t_object *lst, t_ray *ray, float *tmin)
{
	t_object	*p;
	float		t;
	t_ray		ra;

	t = INFINITY;
	p = lst;
	while (p)
	{
		ra = ft_transform_ray(p, ray, 1);
		if (p->type == SPHERE)
		{
			if (sphere_intersect(p, &ra, &t))
				if (t < *tmin)
					return (1);
		}
		else if (p->type == PLANE)
		{
			if (plane_intersect(p, &ra, &t))
				if (t < *tmin)
					return (1);
		}
		else if (p->type == CYLINDER)
		{
			if (cylinder_intersect(p, &ra, &t))
				if (t < *tmin)
					return (1);
		}
		else if (p->type == CONE)
		{
			if (cone_intersect(p, &ra, &t))
				if (t < *tmin)
					return (1);
		}
		p = p->next;
	}
	return 0;
}

// void  ft_print_vect(t_vec v){
// 	printf("x : %.2f y : %.2f z : %.2f\n", v.x, v.y, v.z);
// }

void update(t_mx *mx)
{
	t_ray 	ray;
	t_hit	hit;
	int		y;
	int		x;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ray = camera_ray(&mx->cam, x, y);
			hit.t = INFINITY;
			if (raycast(mx->objects, &ray, &hit))
			{
				mx->rt[(WIN_H - 1 - y) *  WIN_W + x] = ft_shade_object(&hit, mx->lights, mx->objects, &ray);
			}
			x++;
		}
		y++;
	}
}

int     main(int ac, char **av)
{
    t_mx    v;

    if (ac == 2)
    {
        if (av[1])
        {
			ft_bzero(&v, sizeof(t_mx));
			//ft_memset(&v, 0, sizeof(t_mx));
            if (!ft_open(av[1], &v)){
                ft_putstr("error! please try a valid configuration file.\n");
				exit(0);
            }
            else
				run(&v);
        }
    }
    else
        ft_usage();
    return (0);
}