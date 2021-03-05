/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/05 16:28:46 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color	multip_color(t_color c1, t_color c2)
{
	t_color	new;
	float	tmp;

	tmp = c1.x * c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y * c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.z * c2.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

t_color	fraction(t_color c, double fract)
{
	t_color	new;
	double	tmp;

	tmp = c.x * fract;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.y * fract;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.z * fract;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

int		rgb(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x * 255;
	ptr[1] = color.y * 255;
	ptr[0] = color.z * 255;
	ptr[3] = 0;
	return (new);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	new;
	double	tmp;

	tmp = c1.x + c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y + c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c2.z + c1.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

unsigned int			light_effect(t_rt *rt, t_object *o, t_ray *ray) //TODO : static
{
	double			n_l;
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;
	t_object		object;
	t_light			li;

	i = 0;
	lights = rt->lights;
	copy_obj(&object, o);
	tmp_res[1] = ambient(&object, rt->ambient);
	while (lights)
	{
		li.intensity = lights->intensity;
		li.color = lights->color;
		li.position = lights->position;
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		li.direction = vect_sub(li.position, ray->hit_point);
		li.d = sqrtf(dot(li.direction, li.direction));
		li.direction = normalize(li.direction);
		n_l = dot(object.normal, li.direction);
		ray->refraction_index = object.refraction_index;
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(&li, n_l, &object));
		tmp_res[0] = add_color(tmp_res[0], specular(&li, ray, &object));
		// if (object.is_ref)
			tmp_res[0] = add_color(tmp_res[0], reflex_col(rt, *ray, &object, lights));
		// if (object.is_transp)
			tmp_res[0] = add_color(tmp_res[0], refract_color(rt, *ray, &object, lights));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, &li, &object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}

t_color inttorgb(int m)
{
	t_color rgb;

	rgb.x = ((m >> 16) & 255) / 255.0;
	rgb.y = ((m >> 8) & 255) / 255.0;
	rgb.z = (m & 255) / 255.0;
	return (rgb);
}

void			texture_clr(t_object **object, t_point hit)
{
	double	phi;
	double	theta;
	double	u;
	double	v;
	t_vect3	tt;
	t_object *obj;

	obj = *object;
	tt = vect_sub(hit, obj->position);
	tt = rotation_xyz(tt, obj->rotation);
	if (obj->type == CONE)
		theta = acos((double)(tt.y / obj->angle));
	else
		theta = acos((double)(tt.y / obj->radius));
	phi = atan2(tt.z, tt.x);
	u = (-phi + (M_PI)) / (double)(2.0 * M_PI);
	v = theta / M_PI;
	u *= obj->texture->w;
	v *= obj->texture->h;
	if ((int)v * obj->texture->w + (int)u < (obj->texture->w * obj->texture->h))
		obj->color = inttorgb(obj->texture->data_pixels[(int)v * obj->texture->w + (int)u]);
}

void			texture_clr_plane(t_object **object, t_point hit)
{
	double	phi;
	double	theta;
	double	u;
	double	v;
	t_vect3	tt;
	t_object *obj;

	obj = *object;
	tt = vect_sub(hit, obj->position);
	u = fabs(fmod(tt.x, 1.0));
	v = fabs(fmod(tt.z, 1.0));
	u *= obj->texture->w;
	v *= obj->texture->h;
	if ((int)v * obj->texture->w + (int)u < (obj->texture->w * obj->texture->h))
		obj->color = inttorgb(obj->texture->data_pixels[(int)v * obj->texture->w + (int)u]);
}


int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	int color;
	double n_l;
	t_vect3 dir;

	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	if (close_obj->texture && (close_obj->type == SPHERE || close_obj->type == CYLINDER\
	|| close_obj->type == CONE || close_obj->type == PLANE))
	{
		if (close_obj->type != PLANE)
			texture_clr(&close_obj, ray->hit_point);
		else
			texture_clr_plane(&close_obj, ray->hit_point);
	}
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}
