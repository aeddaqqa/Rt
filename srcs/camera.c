/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:19:50 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:28:28 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		cam_cord_system(t_cam *cam)
{
	t_vector	tmp;

	tmp = sub_vector(cam->l, cam->o);
	cam->cords.w = normalize(tmp);
	tmp = cross_prod(cam->cords.w, cam->up);
	cam->cords.u = normalize(tmp);
	cam->cords.v = cross_prod(cam->cords.u, cam->cords.w);
}

static t_cam	*init_camera(t_rt *rt)
{
	t_cam	*new;

	if (!(new = malloc(sizeof(t_cam))))
		destroy(rt, MALLOC_ERROR);
	new->o = rt->null;
	new->l = rt->null;
	new->up = rt->null;
	new->fov = 0.0;
	new->ratio = 0.0;
	new->plan_h = 0.0;
	new->plan_w = 0.0;
	new->cords.w = rt->null;
	new->cords.u = rt->null;
	new->cords.v = rt->null;
	return (new);
}

static void		check_cam_args(t_rt *rt, char ***s)
{
	char	**data;

	data = *s;
	if (data && data[0] && (!data[1] || !data[1][0]))
	{
		ft_putendl("CAMERA");
		ft_putstr("ARGUMENT: ");
		ft_putendl(data[0]);
		ft_putendl("HAS NO VALUE");
		ft_strdel(&data[0]);
		free_double_ptr(s);
		destroy(rt, OBJECT_PROPERTY);
	}
}

void			new_camera(t_rt *rt, int fd)
{
	int		comp;
	char	**s;

	comp = 4;
	rt->cam = init_camera(rt);
	while (comp--)
	{
		if (!(s = value(rt, fd)))
			continue;
		check_cam_args(rt, &s);
		is_vect(s[0]) == 'o' ? (rt->cam->o = read_vector(&s[1])) : rt->null;
		is_vect(s[0]) == 'l' ? rt->cam->l = read_vector(&s[1]) : rt->null;
		is_vect(s[0]) == 'u' ? rt->cam->up = read_vector(&s[1]) : rt->null;
		is_scalar(s[0]) == 'f'\
			? rt->cam->fov = read_scalar(&s[1]) * PI / 180.0 : 0;
		ft_strdel(&s[0]);
	}
	rt->cam->o.z += 0.0005;
	rt->cam->ratio = (double)W / H;
	rt->cam->plan_h = 1 / tan(rt->cam->fov);
	rt->cam->plan_w = rt->cam->plan_h * rt->cam->ratio;
	cam_cord_system(rt->cam);
}
