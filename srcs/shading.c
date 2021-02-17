/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:53:30 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 18:55:02 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int rgba(t_color color)
{
    int new;
    char *ptr;

    ptr = (char *)&new;
    ptr[2] = color.x;
    ptr[1] = color.y;
    ptr[0] = color.z;
    ptr[3] = 0;
    return (new);
}

int shadow_cast(t_object *lst, t_ray *ray, double tmin)
{
    double t;

    t = INFINITY;
    while (lst)
    {
        if (lst->type == SPHERE)
            ft_sphere_intersect(lst, ray, &t);
        else if (lst->type == PLANE)
            ft_plane_intersect(lst, ray, &t);
        else if (lst->type == CYLINDER)
            ft_cylinder_intersect(lst, ray, &t);
        else if (lst->type == CONE)
            ft_cone_intersect(lst, ray, &t);
        else if (lst->type == BOX)
            box_intersect(lst, ray, &t);
        else if (lst->type == PARALLELOGRAM)
            ft_parallelogram_intersect(lst, ray, &t);
        if (t < tmin)
            return (1);
        lst = lst->next;
    }
    return (0);
}

t_vect3 lit_comp(t_light *light, t_vect3 light_dir, t_hit *hit, t_ray *ray)
{
    float lambert;
    t_vect3 color;
    float reflect;
    float phong_term;
    t_vect3 phong_dir;

    color = (t_vect3){0.0f, 0.0f, 0.0f};

    // light->color.x = light->color.x / 255;
    // light->color.y = light->color.y / 255;
    // light->color.z = light->color.z / 255;
    // hit->object->color.x = hit->object->color.x / 255;
    // hit->object->color.y = hit->object->color.y / 255;
    // hit->object->color.z = hit->object->color.z / 255;
    // light->color = v_c_prod(light->color, 1 / 255);
    // hit->object->color = v_c_prod(hit->object->color, 1 / 255);

    color.x = 0.05 * light->color.x * hit->object->color.x;
    color.y = 0.05 * light->color.y * hit->object->color.y;
    color.z = 0.05 * light->color.z * hit->object->color.z;
    lambert = fmax(0.0f, dot(light_dir, hit->n));
    color = vect_add(color, v_c_prod(hit->object->color, lambert));
    reflect = 2.0f * (dot(light_dir, hit->n));
    phong_dir = vect_sub(light_dir, v_c_prod(hit->n, reflect));
    phong_term = fmax(dot(phong_dir, ray->direction), 0.0f);
    phong_term = 1.0f * powf(phong_term, 90.0f) * 1.0f;
    color = vect_add(color, v_c_prod(light->color, phong_term));
    color.x = color.x * light->color.x * light->intensity / 10;
    color.y = color.y * light->color.y * light->intensity / 10;
    color.z = color.z * light->color.z * light->intensity / 10;
    // color.x = color.x * light->color.x * light->intensity;
    // color.y = color.y * light->color.y * light->intensity;
    // color.z = color.z * light->color.z * light->intensity;

    return (color);
}

float clamp(float value, float min, float max)
{
    if (value < min)
    {
        value = min;
    }
    else if (value > max)
    {
        value = max;
    }
    return (value);
}

t_vect3 clamp_vec(t_vect3 v)
{
    v.x = clamp(v.x * 255., 0.0f, 255.0f);
    v.y = clamp(v.y * 255., 0.0f, 255.0f);
    v.z = clamp(v.z * 255., 0.0f, 255.0f);
    return (v);
}

/*int rgb_to_int(t_vect3 v)
{
    int red;
    int green;
    int blue;
    int rgb;

    red = (int)v.x;
    green = (int)v.y;
    blue = (int)v.z;
    rgb = red;
    rgb = (rgb << 8) + green;
    rgb = (rgb << 8) + blue;
    return (rgb);
}*/

int ft_shade_object(t_hit *hit, t_light *lights, t_object *lst, t_ray *ray)
{
    t_light *light;
    t_vect3 color;
    t_vect3 light_dir;
    t_ray shadow_ray;
    double t;

    color = (t_vect3){0.0f, 0.0f, 0.0f};
    shadow_ray.origin = hit->p;
    light = lights;
    while (light)
    {
        light_dir = normalize(vect_sub(light->position, hit->p));
        shadow_ray.direction = light_dir;
        t = ft_magnitude(vect_sub(light->position, hit->p));
        if (!shadow_cast(lst, &shadow_ray, t))
            color = vect_add(color, lit_comp(light, light_dir,
                                             hit, ray));
        light = light->next;
    }
    //return (rgba(hit->object->color));
    // return (rgba(color));
    //return (color);
    return (rgb_to_int(clamp_vec(color)));
}