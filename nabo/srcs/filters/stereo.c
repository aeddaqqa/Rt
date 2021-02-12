/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:17:59 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/08 16:46:23 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	img_red(int *red, int *img)
{
	t_vec	rgb;
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		rgb.x = 255 / 2;
		rgb.y = ((img[i] >> 8) % 256) / 2;
		rgb.z = (img[i] % 256) / 2;
		red[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
}

void	img_green(int *gren, int *img)
{
	t_vec	rgb;
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		rgb.x = (img[i] >> 16) / 2;
		rgb.y = 255 / 2;
		rgb.z = (img[i] % 256) / 2;
		gren[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
}

void	merge_3d(int *img, int *green, int *red)
{
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		if (i % 2 == 0)
			img[i] = green[i];
		else if (img[i - 10])
			img[i - 10] = red[i];
		i++;
	}
	free(green);
	free(red);
}

void	img_ddd(int *img)
{
	int *red;
	int *green;
	int	k;
	int	i;

	k = WIN_W;
	i = 0;
	red = (int *)malloc(WIN_W * WIN_H * 4);
	green = (int *)malloc(WIN_W * WIN_H * 4);
	img_green(green, img);
	img_red(red, img);
	merge_3d(img, green, red);
	while (i < WIN_W * WIN_H)
	{
		if (i > k - 10 && i < k + 10)
			img[i] = 0;
		if (i > k + 10)
			k = k + WIN_W;
		i++;
	}
}
