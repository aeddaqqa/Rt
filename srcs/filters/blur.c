/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:27:21 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/07 18:03:59 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	beautify(int *blur, int *img)
{
	int i;
	int k;

	i = 0;
	k = W;
	while (i < W * H)
	{
		if (i > k - 20 && i < k + 20)
			blur[i] = 0;
		if (i > k + 20)
			k = k + W;
		i++;
	}
	ft_memcpy(img, blur, W * H * 4);
	free(blur);
}

void	blurr(int *img)
{
	t_clr	rgb;
	int		*blur;
	int		cnt;
	int		i;

	blur = (int*)malloc(sizeof(int) * W * H * 4);
	ft_memcpy(blur, img, W * H * 4);
	i = 0;
	while (i < W * H)
	{
		cnt = 0;
		rgb = (t_clr){0, 0, 0};
		while (cnt < 20)
		{
			rgb.r += (img[i + cnt] >> 16);
			rgb.g += (img[i + cnt] >> 8) % 256;
			rgb.b += img[i + cnt] % 256;
			cnt++;
		}
		blur[i] = ((rgb.r / cnt) << 16) + ((rgb.g / cnt) << 8) + (rgb.b / cnt);
		i++;
	}
	beautify(blur, img);
}
