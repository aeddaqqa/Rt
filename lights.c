#include "./header.h"

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

t_color			ambient(t_object *obj, double amb)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, amb);
	color = vect_prod(color, obj->color);
	return (color);
}

t_color			diffuse(t_light *light, double n_l, t_object *object)
{
	t_color		color;

	color = multip_color(fraction(light->color, light->intensity), object->color);
	color = fraction(color, n_l * .8);
	return (color);
}

t_color			specular(t_light *l, t_ray *ray, t_object *object)
{
	t_color			color;
	t_vect3		h;
	unsigned int	alpha;
	double			dot_p;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->direction, ray->direction));
	if ((dot_p = dot(object->normal, h)) <= 0)
		return (color);
	dot_p = powf(dot_p, alpha);
	color = fraction(l->color, dot_p * l->intensity * 1.0); // TODO: specular intensity
	return (color);
}

unsigned int			light_effect(t_rt *rt, t_object *object, t_ray *ray) //TODO : static
{
	double			n_l;
	t_color			color[1];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;
	t_light			li;

	i = 0;
	lights = rt->lights;
	tmp_res[1] = ambient(object, .1);
	while (lights)
	{
		li.intensity = lights->intensity;
		li.color = lights->color;
		li.position = lights->position;
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		li.direction = vect_sub(li.position, ray->hit_point);
		li.d = sqrtf(dot(li.direction, li.direction));
		li.direction = normalize(li.direction);
		n_l = dot(object->normal, li.direction);
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(&li, n_l, object));
		tmp_res[0] = add_color(tmp_res[0], specular(&li, ray, object));
		color[i++] = fraction(tmp_res[0], 1);
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}

t_color int_to_rgb(int m)
{
	t_color rgb;

	rgb.x = ((m >> 16) & 255) / 255.0;
	rgb.y = ((m >> 8) & 255) / 255.0;
	rgb.z = (m & 255) / 255.0;
	return (rgb);
}

t_vect3	plane_normal(t_object *object, t_ray *ray)
{
	if (dot(ray->direction, object->orientation) < 0)
		return (object->orientation);
	return (v_c_prod(object->orientation, -1));
}

t_vect3			cone_normal(t_object *cone, t_ray *ray)
{
	// t_vect3		p;
	t_vect3	new;
	t_point		p;
	double		dv_xv[2];
	double		m;
	t_vect3	x;

	p = v_c_prod(ray->direction, ray->t);
	p = vect_add(ray->origin, p);
	x = vect_sub(ray->origin, cone->position);
	dv_xv[0] = dot(ray->direction, cone->orientation);
	dv_xv[1] = dot(x, cone->orientation);
	m = (dv_xv[0] * ray->t + dv_xv[1]) * (1 + powf(tan(cone->angle / 2.0), 2));
	new = v_c_prod(cone->orientation, m);
	new = vect_add(new, cone->position);
	new = vect_sub(p, new);
	if (dot(ray->direction, new) > 0)
		new = v_c_prod(new, -1.0);
	return (normalize(new));

	// p = v_c_prod(p, 1.0 / cone->angle);
	// return (ft_vector(p.x, 0.001, p.z));
}

int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	int color;
	double n_l;
	t_vect3 dir;
	double phi,theta;
	double u,v;

	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	theta = acos((double)(ray->hit_point.y / close_obj->radius));
	phi = atan2(ray->hit_point.z, ray->hit_point.x);
	u = (-phi + M_PI) / (double)(2.0 * M_PI);
	v = theta / M_PI;
	// v = ray->hit_point.y / close_obj->height;
	u *= 1024;
	v *= 512;
	return (rt->sdl->tex[(int)v * 1024 + (int)u]);
	if ((int)v * 1024 + (int)u < 1024 * 512)
		close_obj->color = int_to_rgb(rt->sdl->tex[(int)v * 1024 + (int)u]);
	close_obj->normal = cone_normal(close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}

// int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
// {
// 	int color;
// 	double n_l;
// 	t_vect3 dir;

// 	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
// 	ray->t = t;
// 	close_obj->normal = sphere_normal(close_obj, ray);
// 	rt->lights->direction = vect_sub(rt->lights->position, ray->hit_point);
// 	rt->lights->direction = normalize(rt->lights->direction);
// 	n_l = dot(close_obj->normal, rt->lights->direction);
// 	if (n_l >= 0.000001)
// 		v_c_prod(close_obj->color, n_l);
// 	return (rgb(close_obj->color));
// }