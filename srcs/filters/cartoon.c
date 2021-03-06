/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:12 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/06 16:02:57 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	palette2(t_clr *colh)
{
	colh[25] = (t_clr){254, 245, 231};
	colh[26] = (t_clr){212, 172, 13};
	colh[27] = (t_clr){241, 196, 15};
	colh[28] = (t_clr){244, 208, 63};
	colh[29] = (t_clr){126, 81, 9};
	colh[30] = (t_clr){251, 238, 230};
	colh[31] = (t_clr){202, 111, 30};
	colh[32] = (t_clr){230, 126, 34};
	colh[33] = (t_clr){235, 152, 78};
	colh[34] = (t_clr){110, 44, 0};
	colh[35] = (t_clr){248, 249, 249};
	colh[36] = (t_clr){208, 211, 212};
	colh[37] = (t_clr){236, 240, 241};
	colh[38] = (t_clr){240, 243, 244};
	colh[39] = (t_clr){98, 101, 103};
	colh[40] = (t_clr){242, 244, 244};
	colh[41] = (t_clr){131, 145, 146};
	colh[42] = (t_clr){149, 165, 166};
	colh[43] = (t_clr){170, 183, 184};
	colh[44] = (t_clr){66, 73, 73};
	colh[45] = (t_clr){234, 236, 238};
	colh[46] = (t_clr){46, 64, 83};
	colh[47] = (t_clr){44, 62, 80};
	colh[48] = (t_clr){93, 109, 126};
	colh[49] = (t_clr){23, 32, 42};
}

void	palette1(t_clr *colh)
{
	colh[0] = (t_clr){120, 40, 31};
	colh[1] = (t_clr){169, 50, 38};
	colh[2] = (t_clr){192, 57, 43};
	colh[3] = (t_clr){205, 97, 85};
	colh[4] = (t_clr){253, 237, 236};
	colh[5] = (t_clr){74, 35, 90};
	colh[6] = (t_clr){136, 78, 160};
	colh[7] = (t_clr){155, 89, 182};
	colh[8] = (t_clr){157, 122, 197};
	colh[9] = (t_clr){244, 236, 247};
	colh[10] = (t_clr){27, 79, 114};
	colh[11] = (t_clr){136, 78, 160};
	colh[12] = (t_clr){41, 128, 185};
	colh[13] = (t_clr){84, 153, 199};
	colh[14] = (t_clr){235, 245, 251};
	colh[15] = (t_clr){11, 83, 69};
	colh[16] = (t_clr){136, 78, 160};
	colh[17] = (t_clr){26, 188, 156};
	colh[18] = (t_clr){72, 201, 176};
	colh[19] = (t_clr){232, 246, 243};
	colh[20] = (t_clr){24, 106, 59};
	colh[21] = (t_clr){136, 78, 160};
	colh[22] = (t_clr){39, 174, 96};
	colh[23] = (t_clr){82, 190, 128};
	colh[24] = (t_clr){234, 250, 241};
}

int		init(t_clr *colh)
{
	palette1(colh);
	palette2(colh);
	return (0);
}

void	ft_cartoon(int *img)
{
	t_clr	*colh;
	t_clr	save;
	t_clr	rgb;
	t_z		z;

	colh = malloc(sizeof(t_clr) * 60);
	z.i = init(colh);
	while (z.i++ < W * H)
	{
		z.j = 0;
		z.d = INFINITY;
		rgb = (t_clr){img[z.i] >> 16, (img[z.i] >> 8) % 256, img[z.i] % 256};
		while (z.j++ < 50)
		{
			z.dd = sqrt(pow(rgb.r - colh[z.j].r, 2) + pow(rgb.g - \
						colh[z.j].g, 2) + pow(rgb.b - colh[z.j].b, 2));
			if (z.dd < z.d)
			{
				save = (t_clr)colh[z.j];
				z.d = z.dd;
			}
		}
		img[z.i] = ((int)save.r << 16) + ((int)save.g << 8) + save.b;
	}
	free(colh);
}
