/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:24:56 by chzabakh          #+#    #+#             */
/*   Updated: 2020/12/26 14:25:22 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

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
	free(anti);
}
