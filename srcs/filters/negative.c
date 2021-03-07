/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:24:26 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/07 18:03:34 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	img_neg(int *img)
{
	int		*neg;
	int		res;
	t_vec	rgb;
	int		i;

	res = W * H;
	neg = (int *)malloc(res * 4);
	ft_memcpy(neg, img, res * 4);
	i = 0;
	while (i < res)
	{
		rgb.x = img[i] >> 16;
		rgb.y = (img[i] >> 8) % 256;
		rgb.z = img[i] % 256;
		rgb.x = 255 - rgb.x;
		rgb.y = 255 - rgb.y;
		rgb.z = 255 - rgb.z;
		neg[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, neg, res * 4);
	free(neg);
}
