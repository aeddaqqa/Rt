/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:22:11 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/07 09:40:49 by chzabakh         ###   ########.fr       */
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
	while (i < W * H)
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
	noi = (int*)malloc(sizeof(int) * W * H * 4);
	noimag = (int*)malloc(sizeof(int) * W * H * 4);
	greycalc(grey, noi);
	i = 0;
	while (i < W * H)
	{
		rgb.x = ((img[i] >> 16) * 14 + (noi[i] >> 16)) / 15;
		rgb.y = (((img[i] >> 8) % 256) * 14 + ((noi[i] >> 8) % 256)) / 15;
		rgb.z = ((img[i] % 256) * 14 + (noi[i] % 256)) / 15;
		noimag[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, noimag, W * H * 4);
	free(grey);
	free(noi);
	free(noimag);
}
