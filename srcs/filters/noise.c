/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:22:11 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/08 16:46:13 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	greycalc(int *grey, int *noi)
{
	int		r;
	int		i;

	i = 0;
	grey[0] = 2631720;
	grey[1] = 1973790;
	grey[2] = 1315860;
	while (i < WIN_W * WIN_H)
	{
		grey[3] = noi[i];
		grey[4] = noi[i];
		grey[5] = noi[i];
		r = (rand() % 6);
		noi[i] = grey[r];
		i++;
	}
}

void	img_noise(int *img)
{
	int		*noi;
	int		*noimag;
	int		*grey;
	t_vec	rgb;
	int		i;

	srand(time(0));
	grey = (int*)malloc(sizeof(int) * 6);
	noi = (int*)malloc(sizeof(int) * WIN_W * WIN_H * 4);
	noimag = (int*)malloc(sizeof(int) * WIN_W * WIN_H * 4);
	greycalc(grey, noi, i);
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		rgb.x = ((img[i] >> 16) * 3 + (noi[i] >> 16)) / 4;
		rgb.y = (((img[i] >> 8) % 256) * 3 + ((noi[i] >> 8) % 256)) / 4;
		rgb.z = ((img[i] % 256) * 3 + (noi[i] % 256)) / 4;
		noimag[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, noimag, WIN_W * WIN_H * 4);
	free(grey);
	free(noi);
	free(noimag);
}
