/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:23:39 by chzabakh          #+#    #+#             */
/*   Updated: 2021/02/21 14:36:35 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <math.h>
// # include <mlx.h>
# include <time.h>
# include <stdlib.h>
# define WIN_W 720
# define WIN_H 720

typedef	struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef	struct	s_clr
{
	int	r;
	int	g;
	int	b;
}				t_clr;

typedef struct	s_image
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_image;

void			image_create(int *img);
void			img_sepia(int *img);
void			img_noise(int *img);
void			img_neg(int *img);
void			img_grey(int *img);
void			antialiasing(int *img);
void			ft_cartoon(int *img);
void			img_ddd(int *img);
#endif
