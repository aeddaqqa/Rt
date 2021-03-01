#include "./header.h"

double  deg_to_rad(double angle)
{
    return (angle * M_PI / 180);
}

t_vect3		cross(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}

double		dot(t_vect3 a, t_vect3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		ft_magnitude(t_vect3 v)
{
	t_vect3	c;

	c.x = v.x * v.x;
	c.y = v.y * v.y;
	c.z = v.z * v.z;
	return (sqrt(c.x + c.y + c.z));
}

t_vect3		ft_negative(t_vect3 v)
{
	t_vect3	c;

	c.x = -1.0 * v.x;
	c.y = -1.0 * v.y;
	c.z = -1.0 * v.z;
	return (c);
}

t_vect3	normalize(t_vect3 vec)
{
	double	mod;

	mod = sqrtf(dot(vec, vec));
	return ((t_vect3){vec.x / mod, vec.y / mod, vec.z / mod});
}

t_vect3	v_c_add(t_vect3 u, double v)
{
	t_vect3	w;

	w.x = u.x + v;
	w.y = u.y + v;
	w.z = u.z + v;
	return (w);
}

t_vect3		v_c_prod(t_vect3 c, double scalar)
{
	c.x *= scalar;
	c.y *= scalar;
	c.z *= scalar;
	return (c);
}

t_vect3		vect_add(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vect3		vect_sub(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vect3	vect_prod(t_vect3 u, t_vect3 v)
{
	t_vect3	w;

	w.x = u.x * v.x;
	w.y = u.y * v.y;
	w.z = u.z * v.z;
	return (w);
}

t_ray	*ray_init(t_rt *rt, double x, double y, double r1, double r2)
{
	t_ray		*new;
	double		px;
	double		py;
	t_vect3	tmp;
	t_vect3	tmp2;

	new = malloc(sizeof(t_ray));
	new->origin = rt->cameras->o;
	px = (2 * ((double)x + r1) / W) - 1;
	py = 1 - (2 * ((double)y + r2) / H);
	tmp = v_c_prod(rt->cameras->cords.u, px * rt->cameras->plan_w);
	tmp2 = v_c_prod(rt->cameras->cords.v, py * rt->cameras->plan_h);
	tmp = vect_add(tmp, tmp2);
	tmp = vect_add(tmp, rt->cameras->cords.w);
	new->direction = normalize(tmp);
	new->reflect_nb = 1;
	new->reflexion_index = 1.3;
	return (new);
}

double	equa_solu(double a, double b, double delta)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0.0) || (t1 >= 0.0 && t2 < 0.0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0.0) || (t2 >= 0.0 && t1 < 0.0))
		return (t2);
	// printf("f");
	return (-1);
}

double		hit_plane(t_object *object, t_ray *ray)
{
	double		t;
	double		a;
	double		b;
	t_vect3		oc;

	object->orientation = normalize(object->orientation);
	oc = vect_sub(ray->origin, object->position);
	a = dot(oc, object->orientation);
	b = dot(ray->direction, object->orientation);
	if (b == 0 || a * b >= 0)
		return (-1.0);
	t = -a / b;
	return (t);
}


t_vect3		cylinder_normal(t_object *object, t_ray *ray)
{
	double		m;
	t_vect3	n;
	t_vect3	p;


	m = dot(ray->direction, object->orientation) * ray->t;
	m += dot(vect_sub(ray->origin, object->position), object->orientation);
	p = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
	n = normalize(vect_sub(vect_sub(p, object->position),\
				v_c_prod(object->orientation, m)));
	m = 0.0;
	if (object->height <= 0)
	{
		return (n);
	}
	if (ray->ret < 0)
	{
		n = v_c_prod(object->orientation, -1.0);
		return (n);
	}
	else if (ray->ret > 1)
	{
		n = object->orientation;
		return (n);
	}
	return (n);
}

static int 	ft_cylinder_cap(t_ray *ray, double *t, t_vect3 position, t_vect3 n)
{
	float	ddn;
	float	t1;
	t_vect3	dist;
	
	ray->ret = 0;

	ddn = dot(ray->direction, n);
	if (ddn <= 1.0e-6 && ddn >= -1.0e-6)
		return (-1.0);
	dist = vect_sub(position, ray->origin);
	t1 = (dot(dist, n)) / ddn;
	// if (t1 < *t && t1 > 1e-2)
	if (t1 >= 0.0)
	{
		*t = t1;
		if (ddn >= 1e-6)
		{
			ray->ret = 2;
			return (2);
		}
		 	ray->ret = 1;
		return (1);
	}
	return (0);
}

static int	ft_cylinder_cap1(t_object *cylinder, t_ray *ray, double *t, float m1)
{
	ray->ret = 0;
	if (m1 < -cylinder->height)
		return (0);
	if (ft_cylinder_cap(ray, t, v_c_prod(cylinder->orientation, -cylinder->height), v_c_prod(cylinder->orientation, -1.0)))
		{
			ray->ret = -1;
			return (-1);
		}
	return (0);
}

double			hit_cylinder(t_object *cylinder, t_ray *ray)
{
	t_vect3	x;
	float	m0;
	float	m1;
	double  t;

	x = vect_sub(ray->origin, cylinder->position);
	cylinder->cyl.a = dot(ray->direction, ray->direction) -\
	pow(dot(ray->direction, cylinder->orientation), 2.0);
	cylinder->cyl.b = 2.0 * (dot(ray->direction, x) -\
	(dot(ray->direction, cylinder->orientation) *\
	dot(x, cylinder->orientation)));
	cylinder->cyl.c = dot(x, x) -\
	pow(dot(x, cylinder->orientation), 2.0) -\
	(cylinder->radius * cylinder->radius);
	cylinder->cyl.delta = (cylinder->cyl.b * cylinder->cyl.b) -\
	(4.0 * cylinder->cyl.a * cylinder->cyl.c);
	if (cylinder->cyl.delta < 0)
		return (-1.0);
	cylinder->cyl.delta = sqrt(cylinder->cyl.delta);
	cylinder->cyl.t1 = (-cylinder->cyl.b + cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	cylinder->cyl.t2 = (-cylinder->cyl.b - cylinder->cyl.delta) /\
	(2 * cylinder->cyl.a);
	if (cylinder->height <= 0)
		return (equa_solu(cylinder->cyl.a, cylinder->cyl.b, cylinder->cyl.delta));
	if (cylinder->cyl.t1 > cylinder->cyl.t2)
	{
		m0 = cylinder->cyl.t1;
		cylinder->cyl.t1 = cylinder->cyl.t2;
		cylinder->cyl.t2 = m0;
	}
	m0 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t1;
	m0 += dot(x, cylinder->orientation);
	m1 = dot(ray->direction, cylinder->orientation) * cylinder->cyl.t2;
	m1 += dot(x, cylinder->orientation);
	ray->ret = 0;
    //printf("m0 : %.2f\t  m1 : %.2f\n", m0, m1);
	if (m0 < -cylinder->height)
	{
		if (ft_cylinder_cap1(cylinder, ray, &t, m1))
		{
			ray->ret = -1;
			return (t);
		}
		
		else return -1;
	}
	else if (m0 >= -cylinder->height && m0 <= cylinder->height)
	{
		if (cylinder->cyl.t1 < 1e-6)// || cylinder->cyl.t1 > ray->t)
			return (-1.0);
		return (cylinder->cyl.t1);
	}
	else if (m0 > cylinder->height)
	{
		if (m1 > cylinder->height)
			return (-1.0);
		if (ft_cylinder_cap(ray, &t, v_c_prod(cylinder->orientation, cylinder->height), cylinder->orientation))
			{
				ray->ret = 2;
				return (t);
			}
	}
	return (-1.0);
}

t_vect3		sphere_normal(t_object *obj, t_ray *ray)
{
	t_vect3	n;

	n = normalize(vect_sub(ray->hit_point, obj->position));
	return (n);
}

double	hit_sphere(t_object *object, t_ray *ray)
{
	t_vect3		oc;
	double		a;
	double		b;
	double		c;
	double		delta;

	oc = vect_sub(ray->origin, object->position);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(ray->direction, oc);
	c = dot(oc, oc) - object->radius * object->radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return (-1.0);
	return (equa_solu(a, b, delta));
}

void			new_camera(t_rt *rt)
{
	t_vect3 tmp;

	rt->cameras->o.z += 0.0005;
	rt->cameras->ratio = (double)(W / H);
	rt->cameras->plan_h = 1 / tan(rt->cameras->fov);
	rt->cameras->plan_w = rt->cameras->plan_h * rt->cameras->ratio;
	tmp = vect_sub(rt->cameras->l, rt->cameras->o);
	rt->cameras->cords.w = normalize(tmp);
	tmp = cross(rt->cameras->cords.w, rt->cameras->up);
	rt->cameras->cords.u = normalize(tmp);
	rt->cameras->cords.v = cross(rt->cameras->cords.u, rt->cameras->cords.w);
}

static void		ft_cone_init(t_cone *cone, t_object *o, t_ray *r)
{
	double a = pow(dot(r->direction, o->orientation), 2) - pow(cos(o->angle), 2.0);
	t_vect3 x = vect_sub(r->origin, o->position);
	double b = 2 * (dot(r->direction, o->orientation) * (dot(x, o->orientation)) - dot(r->direction, x) * pow(cos(o->angle), 2.0));
	double c = (pow(dot(x, o->orientation), 2) - dot(x, x) * pow(cos(o->angle), 2.0));
	cone->d.a = a;
	cone->d.b = b;
	cone->d.c = c;
	cone->d.delta = cone->d.b * cone->d.b - 4.0 * cone->d.a * cone->d.c;
}

double			hit_cone(t_object *c, t_ray *r)
{
	t_cone		a;
	int			ret;
	t_vect3		cp;
	float		h;
	double		t;

	ft_cone_init(&a, c, r);
	if (a.d.delta < 0.00001)
		return (-1.0);
	// a.d.delta = sqrt(a.d.delta);
	if (c->height <= 0)
		return (equa_solu(a.d.a, a.d.b, a.d.delta));
	t = 0.0001;
	double t1 = (-a.d.b - sqrt(a.d.delta)) / (2 * a.d.a);
   	double  t2 = (-a.d.b + sqrt(a.d.delta)) / (2 * a.d.a);
 	if ((t1 <= t2 && t1 >= 0.0) || (t1 >= 0.0 && t2 < 0.0))
 		t = t1;
 	else if ((t2 <= t1 && t2 >= 0.0) || (t2 >= 0.0 && t1 < 0.0))
 		t = t2;
	else
		return (-1);
	cp = vect_add(r->origin, v_c_prod(r->direction, (t)));
	h = dot(cp, c->orientation);
	if (h < 0 || h > c->height)
		return (-1.0);
	return (t);
}


unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			x;
	double			t;
	unsigned int	color;
	t_object		*close_object;
	t_object		*tmp;
	t_object		tmp2;

	tmp = rt->objects;
	ray->t = -1.0;
	t = -1.0;
	color = 0;
	while (tmp)
	{
		x = hit_cone(tmp, ray);
		if (x != -1 && (x < t || t == -1.0))
		{
			close_object = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1)
		return (light(close_object, ray, rt, t));
		// return (0xff);
	return (0);
}

void		draw_scene(t_rt *rt, int x, int y)
{
	t_color	c;
	t_ray *ray;

	ray = ray_init(rt, x, y, .5, .5);
	rt->sdl->data[y * W + x] = pixel_color(rt, ray);
	free(ray);
}

void draw(t_rt *rt)
{
	int		y;
	int		x;

	new_camera(rt);
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			draw_scene(rt, x ,y);
			x++;
		}
		y++;
	}
}