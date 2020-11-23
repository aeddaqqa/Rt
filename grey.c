void        img_grey(int *img)
{
	int *grey;
	int	res;
	t_vec rgb;
	t_vec tmp;
	int		i;

	res = WIN_W * WIN_H;
	grey = (int *)malloc(res * 4);
	ft_memcpy(grey, img, res * 4);
	i = 0;
	while (i < res)
	{
		rgb.x = img[i] >> 16;
		rgb.y = (img[i] >> 8) % 256;
		rgb.z = img[i] % 256;
		rgb.x = (rgb.x * 0.2126);
		rgb.y = (rgb.y * 0.7152);
		rgb.z = (rgb.z * 0.0722);
		tmp.x = rgb.x + rgb.y + rgb.z;
		tmp.y = rgb.x + rgb.y + rgb.z;
		tmp.z = rgb.x + rgb.y + rgb.z;
		rgb = tmp;
		rgb.x = rgb.x > 255 ? 255 : rgb.x;
		rgb.y = rgb.y > 255 ? 255 : rgb.y;
		rgb.z = rgb.z > 255 ? 255 : rgb.z;
		grey[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, grey, res * 4);
	free(grey);
}

img_grey(m.img_str);
mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
