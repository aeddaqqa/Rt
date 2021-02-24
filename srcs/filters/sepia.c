/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:12:57 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/23 18:47:45 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	img_sepia(int *img)
{
	int		*sep;
	t_vec	rgb;
	t_vec	tmp;
	int		i;

	sep = (int *)malloc(W * H * 4);
	ft_memcpy(sep, img, W * H * 4);
	i = 0;
	while (i < W * H)
	{
		rgb.x = img[i] >> 16;
		rgb.y = (img[i] >> 8) % 256;
		rgb.z = img[i] % 256;
		tmp = rgb;
		rgb.x = (tmp.x * .393) + (tmp.y * .769) + (tmp.z * .189);
		rgb.y = (tmp.x * .349) + (tmp.y * .686) + (tmp.z * .168);
		rgb.z = (tmp.x * .272) + (tmp.y * .534) + (tmp.z * .131);
		rgb.x = rgb.x > 255 ? 255 : rgb.x;
		rgb.y = rgb.y > 255 ? 255 : rgb.y;
		rgb.z = rgb.z > 255 ? 255 : rgb.z;
		sep[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, sep, W * H * 4);
	free(sep);
}
