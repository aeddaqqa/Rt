/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:46:42 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/08 16:45:52 by chzabakh         ###   ########.fr       */
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
	image->file_size = (WIN_W * WIN_H * 4) + 54;
	image->reserved1 = 0;
	image->reserved2 = 0;
	image->offset_bits = 54;
	image->size_header = 40;
	image->width = WIN_W;
	image->height = WIN_H;
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

	row = WIN_H - 1;
	buf = malloc((WIN_W * WIN_H * 4) + 54);
	while (row >= 0)
	{
		col = 0;
		while (col < WIN_W)
		{
			color = img[(WIN_H - row) *
				WIN_W + col];
			buf[row * WIN_W * 3 + col * 3 + 0] = color;
			buf[row * WIN_W * 3 + col * 3 + 1] = color >> 8;
			buf[row * WIN_W * 3 + col * 3 + 2] = color >> 16;
			col++;
		}
		row--;
	}
	write(file, buf, (WIN_W * WIN_H * 4) + 54);
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
