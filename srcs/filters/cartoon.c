/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:12 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/04 18:38:18 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		sharp(int *img)
{
	int		*anti;
	int		res;
	int		i;
	t_clr	rgb;

	res = W * H;
	anti = (int *)malloc(res * 4);
	ft_memcpy(anti, img, res * 4);
	i = W + 1;
	while (i < res)
	{
		rgb.r = (((img[i] >> 16) * 4) - (img[i - W] >> 16) - \
				(img[i - 1] >> 16) - (img[i - W - 1] >> 16));
		rgb.g = ((((img[i] >> 8) % 256) * 4) - (img[i - W] >> 8) % 256 \
				- (img[i - 1] >> 8) % 256 - (img[i - W - 1] >> 8) % 256);
		rgb.b = (((img[i] % 256) * 4) - (img[i - W] % 256) - \
				(img[i - 1] % 256) - img[i - W - 1] % 256);
		anti[i] = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
		i++;
	}
	ft_memcpy(img, anti, res * 4);
	free(anti);
}

void		ft_cartoon(int *img)
{
	int i;

	i = 0;
	while (i++ < 10)
		antialiasing(img);
	sharp(img);
}
