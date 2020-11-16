/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:08:53 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/14 18:09:05 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam     ft_camera_create(t_vec pos, t_vec at, t_vec vup, float vfov)
{
    t_cam   cam;
    float   theta;
    float   half_height;
    float   half_width;

    pos.z += 0.01; //
    cam.pos = pos;
    cam.fov = vfov; //vertical field of view of camera//
    theta = vfov * M_PI / 180.0; // theta is the angle of vfov in radien//
    half_height = tanf(theta / 2.0);
    half_width = ((float)WIN_W / (float)WIN_H) * half_height;
    cam.forward = ft_normalize(ft_vectorsub(pos, at)); // distance between the lookat and the cam pos//
    cam.u = ft_normalize(ft_crossproduct(vup, cam.forward)); // u is the width of the cam plane.. vup is the vector mtwazi m3a y axis dyal camera //
    cam.v = ft_crossproduct(cam.forward, cam.u); // v is the height of the cam plane//
    cam.lower_left_corner = ft_vectoradd(ft_vectormulti(cam.u, half_width), ft_vectormulti(cam.v, half_height));
    cam.lower_left_corner = ft_vectoradd(cam.lower_left_corner, cam.forward);
    cam.lower_left_corner = ft_vectorsub(cam.pos, cam.lower_left_corner);
    cam.horizontal = ft_vectormulti(cam.u, 2.0 * half_width);
    cam.vertical =  ft_vectormulti(cam.v, 2.0 * half_height);
    return (cam);

}

t_ray       camera_ray(t_cam *cam, int x, int y)
{
	t_ray ray;
	t_vec tmp;

	float s;
    float t;

	s = (float)x / (WIN_W);	
	t = (float)y / (WIN_H);
	tmp = ft_vectoradd(ft_vectormulti(cam->horizontal, s),  ft_vectormulti(cam->vertical, t));
	tmp = ft_vectoradd(cam->lower_left_corner, tmp);
	ray.source = cam->pos;
	ray.direction = ft_normalize(ft_vectorsub(tmp, cam->pos));
	return (ray);
}