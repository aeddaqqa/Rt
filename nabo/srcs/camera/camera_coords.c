/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:33:59 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 18:34:41 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

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