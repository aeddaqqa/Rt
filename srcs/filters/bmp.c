/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:46:42 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/22 12:51:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	image_header(t_image *image, int file)
{
	unsigned char	str[54];

	ft_bzero(str, 54);
	ft_memcpy(str, "BM", 2);
	ft_memcpy(str + 2, &image->file_size, 4);
	ft_memcpy(str + 10, &image->offset_bits, 4);
	ft_memcpy(str + 14, &image->size_header, 4);
	ft_memcpy(str + 18, &image->width, 4);
	ft_memcpy(str + 22, &image->height, 4);
	ft_memcpy(str + 26, &image->planes, 2);
	ft_memcpy(str + 28, &image->bit_count, 2);
	ft_memcpy(str + 34, &image->image_size, 4);
	write(file, &str, 54);
}

void	fill_data(t_image *image)
{
	image->file_size = (W * H * 4) + 54;
	image->reserved1 = 0;
	image->reserved2 = 0;
	image->offset_bits = 54;
	image->size_header = 40;
	image->width = W;
	image->height = H;
	image->planes = 1;
	image->bit_count = 24;
	image->compression = 0;
	image->image_size = 0;
	image->ppm_x = 0;
	image->ppm_y = 0;
	image->clr_used = 0;
	image->clr_important = 0;
}

void	image_put(int *img, int file)
{
	int				color;
	unsigned char	*buf;
	int				row;
	int				col;

	row = H - 1;
	buf = malloc((W * H * 4) + 54);
	while (row >= 0)
	{
		col = 0;
		while (col < W)
		{
			color = img[(H - row) *
				W + col];
			buf[row * W * 3 + col * 3 + 0] = color;
			buf[row * W * 3 + col * 3 + 1] = color >> 8;
			buf[row * W * 3 + col * 3 + 2] = color >> 16;
			col++;
		}
		row--;
	}
	write(file, buf, (W * H * 4) + 54);
	free(buf);
}

void	image_create(int *img)
{
	t_image	image;
	int		file;

	file = open("./save.bmp", O_RDWR | O_CREAT, 777);
	fill_data(&image);
	image_header(&image, file);
	image_put(img, file);
}
