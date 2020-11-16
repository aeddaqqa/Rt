/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:29 by chzabakh          #+#    #+#             */
/*   Updated: 2020/11/07 09:55:23 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			close_window(void *m)
{
	if (m)
	{
		system("clear");
		exit(0);
	}
	return (0);
}

int			keypress(int keycode, void *m)
{
	if (keycode == 53 && m)
	{
		system("clear");
		exit(0);
	}
	return (0);
}

void		ft_work(t_settings *m, t_mlx *hd)
{
	t_mlx	*lights;
	t_ray	ray;
	t_hit	hit;
	int		x;
	int		y;

	ft_camera(m, hd);
	lights = hd;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ray = camera_ray(m->cam, x, y);
			hit.t = INFINITY;
			if (raycast(hd, &ray, &hit))
				m->img_str[(WIN_H - 1 - y) * WIN_W + x] = ft_shade(&hit, \
						lights, hd, &ray);
			x++;
		}
		y++;
	}
}

void		antialiasing(int *img)
{
	int		*anti;
	int		res;
	int		i;
	t_clr	rgb;

	res = WIN_W * WIN_H;
	anti = (int *)malloc(res * 4);
	ft_memcpy(anti, img, res * 4);
	i = WIN_W + 1;
	while (i < res)
	{
		rgb.r = ((img[i] >> 16) + (img[i - WIN_W] >> 16) + (img[i - 1] >> 16) \
				+ (img[i - WIN_W - 1] >> 16)) / 4;
		rgb.g = ((img[i] >> 8) % 256 + (img[i - WIN_W] >> 8) % 256 \
				+ (img[i - 1] >> 8) % 256 \
				+ (img[i - WIN_W - 1] >> 8) % 256) / 4;
		rgb.b = (img[i] % 256 + img[i - WIN_W] % 256 + img[i - 1] % 256 \
				+ img[i - WIN_W - 1] % 256) / 4;
		anti[i] = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
		i++;
	}
	ft_memcpy(img, anti, res * 4);
}

void		ft_start(t_mlx *hd)
{
	t_settings	m;

	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, WIN_W, WIN_H, "RTv1");
	m.img_ptr = mlx_new_image(m.mlx_ptr, WIN_W, WIN_H);
	m.img_str = (int *)mlx_get_data_addr(m.img_ptr, &m.bpp, &m.l, &m.endin);
	ft_work(&m, hd);
	antialiasing(m.img_str);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_hook(m.win_ptr, 2, 0, keypress, (void *)&m);
	mlx_hook(m.win_ptr, 17, 0, close_window, (void *)&m);
	mlx_loop(m.mlx_ptr);
}
