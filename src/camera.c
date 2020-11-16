/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:37:11 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/21 10:11:44 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray		camera_ray(t_cam cam, int x, int y)
{
	t_ray ray;
	t_vec tmp;
	float s;
	float t;

	s = (float)x / (WIN_W);
	t = (float)y / (WIN_H);
	tmp = vec_add(vec_scale(cam.hrzntl, s), vec_scale(cam.vrtcl, t));
	tmp = vec_add(cam.lwr_lft_crnr, tmp);
	ray.source = cam.pos;
	ray.direction = vec_norm(vec_sub(tmp, cam.pos));
	return (ray);
}

void		ft_camera_create(t_settings *m)
{
	float	theta;
	float	half_height;
	float	half_width;

	m->cam.pos.z += 0.01;
	theta = m->cam.fov * M_PI / 180.;
	half_height = tan(theta / 2.);
	half_width = ((float)WIN_W / (float)WIN_H) * half_height;
	m->cam.fwd = vec_norm(vec_sub(m->cam.pos, m->cam.lkat));
	m->cam.u = vec_cross(m->cam.vup, m->cam.fwd);
	m->cam.v = vec_cross(m->cam.fwd, m->cam.u);
	m->cam.lwr_lft_crnr = vec_add(vec_scale(m->cam.u, half_width), \
			vec_scale(m->cam.v, half_height));
	m->cam.lwr_lft_crnr = vec_add(m->cam.lwr_lft_crnr, m->cam.fwd);
	m->cam.lwr_lft_crnr = vec_sub(m->cam.pos, m->cam.lwr_lft_crnr);
	m->cam.hrzntl = vec_scale(m->cam.u, 2. * half_width);
	m->cam.vrtcl = vec_scale(m->cam.v, 2. * half_height);
}

void		ft_camera(t_settings *m, t_mlx *hd)
{
	t_mlx	*camtmp;

	camtmp = hd;
	while (camtmp->id != 0)
		camtmp = camtmp->next;
	m->cam.pos = hd->pos;
	m->cam.lkat = hd->dir;
	m->cam.fov = 60.;
	m->cam.vup = (t_vec){0, 1, 0};
	ft_camera_create(m);
}
