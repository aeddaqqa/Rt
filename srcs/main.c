/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 18:50:31 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../includes/rt.h"

t_mlx	*init_mlx(t_rt *rt)
{
	t_mlx	*new;
	
	if (!(new = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		free_rt(&rt);
		return (NULL);
	}
	new->ptr = mlx_init();
	new->win = mlx_new_window(new->ptr, W, H, "RT");
	new->img = mlx_new_image(new->ptr, W, H);
	new->data = (int*)mlx_get_data_addr(new->img, &new->bpp,\
	&new->ls, &new->end);
	return (new);
}

void		cam_cord_system(t_cam *cam)
{
	t_vect3	tmp;

    cam->ratio = (double)W / H;
	cam->up = (t_vect3){0.0, 1.0, 0.0};
	cam->plan_h = 1 / tan(cam->fov);
	cam->plan_w = cam->plan_h * cam->ratio;
	tmp = vect_sub(cam->l, cam->o);
	cam->cords.w = normalize(tmp);
	tmp = cross(cam->cords.w, cam->up);
	cam->cords.u = normalize(tmp);
	cam->cords.v = cross(cam->cords.u, cam->cords.w);
}

void		ft_compute_normals(t_hit *hit, t_ray *ray)
{
	t_vect3	x;
	double	m;

	m = 0;
	x = (t_vect3){0, 0, 0};
	if (hit->object->type == SPHERE)
		hit->n = ft_sphere_normal(hit);
	else if (hit->object->type == PLANE)
		hit->n = ft_plane_normal(hit->object);
	else if (hit->object->type == CYLINDER)
		ft_computing_cyl_normal(hit, ray, x, m);
	else if (hit->object->type == CONE)
		hit->n = ft_cone_normal(hit->object, hit->p);
	else if (hit->object->type == BOX)
		hit->n = ft_box_normal(hit->object, hit->p);
	else if (hit->object->type == PARALLELOGRAM)
		hit->n = ft_parallelogram_normal(hit->object);
	else if (hit->object->type == TRIANGLE)
		ft_computing_triangle_normal(hit);
	else if (hit->object->type == ELLIPSOID)
		ft_computing_ellipsoid_normal(hit);
	else if (hit->object->type == PARABOLOID)
		ft_computing_paraboloid_normal(hit);
}

t_ray	*ray_init(t_rt *rt, double x, double y);

 t_ray           raycastloop(t_object *p, t_hit *hit, t_ray *raw, double t)
 {
     t_ray       save;
     t_ray       ray;

     while (p)
     {
         ray = *raw;//ft_transform_ray(p, raw, 1);
         if (p->type == SPHERE)
             ft_sphere_intersect(p, &ray, &t);
         else if (p->type == PLANE)
             ft_plane_intersect(p, &ray, &t);
         else if (p->type == CYLINDER)
             ft_cylinder_intersect(p, &ray, &t);
         else if (p->type == CONE)
             ft_cone_intersect(p, &ray, &t);
         else if (p->type == BOX)
             box_intersect(p, &ray, &t);
         else if (p->type == PARALLELOGRAM)
             ft_parallelogram_intersect(p, &ray, &t);
         if (hit->t > t)
         {
             hit->t = t;
             hit->object = p;
             save = ray;
         }
         p = p->next;
     }
     return (save);
 }

 int             raycast(t_object *lst, t_ray *raw, t_hit *hit)
 {
     t_object    *p;
     double       t;
     t_ray       save;

     t = INFINITY;
     hit->object = NULL;
     hit->t = INFINITY;
     p = lst;
     save = raycastloop(p, hit, raw, t);
     if (hit->object == NULL)
         return (0);
     hit->p = vect_add(save.origin, v_c_prod(save.direction, hit->t));
     ft_compute_normals(hit, &save);
    //  hit->p = ft_translate_object(hit->p, hit->object->trans, 0);
     // hit->p = ft_rotate_object(hit->p, hit->object->rot, 0);
     // hit->n = ft_rotate_object(hit->n, hit->object->rot, 0);
    //  hit->n = normalize(hit->n);
     return (1);
 }

int		rgba(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x;
	ptr[1] = color.y;
	ptr[0] = color.z;
	ptr[3] = 0;
	return (new);
}

int     ft_shade_object(t_hit *hit /*, t_light *lights, t_object *lst , t_ray *ray*/)
{
    // t_light     *light;
    // t_vect3       color;
    // t_vect3       light_dir;
    // // t_ray       shadow_ray;
    // double       t;

    // color = (t_vect3){0.0f, 0.0f, 0.0f};
    // shadow_ray.source = hit->p;
    // light = lights;
    // while (light)
    // {
    //     // light_dir = ft_normalize(vect_add(light->position, hit->p));
    //     // shadow_ray.direction = light_dir;
    //     // t = ft_magnitude(vect_add(light->position, hit->p));
    //     // if (!shadow_cast(lst, &shadow_ray, &t))
    //         // color = ft_vect3toradd(color, ft_lgt_computing(light, light_dir,\
    //     hit, ray));
    //     light = light->next;
    // }
	printf("%lf, %lf, %lf\n", hit->object->color.x, hit->object->color.y, hit->object->color.z);
    return (rgba(hit->object->color));
}

void    draw(t_rt *rt)
{
    t_ray   *ray;
    t_hit   hit;
    int     y;
    int     x;

    y = 0;
    while (y < H)
    {
        x = 0;
        while (x < W)
        {
            ray = ray_init(rt, x, y);
            hit.t = INFINITY;
            if (raycast(rt->objects, ray, &hit))
            {
                rt->mlx->data[y * W + x] = ft_shade_object(&hit);//, rt->lights, rt->objects, ray);
                // mx->rt[(H - 1 - y) * W + x] = 0xff0000;
            }
            x++;
        }
        y++;
    }
}

int		main(int ac, char **av)
{
	char	*file;
	t_rt	*rt;

	file = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		if (!(file = load_file(av[1])))
			exit(0);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!(parse(file, rt)))
		{
			destroy(SYNTAX_ERROR);
			free_rt(&rt);
			free(file);
			exit(0);
		}
		if (!(rt->mlx = init_mlx(rt)))
			destroy(SYNTAX_ERROR);
		cam_cord_system(rt->cameras);
		draw(rt);
		mlx_put_image_to_window(rt->mlx->ptr, rt->mlx->win, rt->mlx->img, 0, 0);
		mlx_loop(rt->mlx->ptr);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
