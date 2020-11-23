void        img_sepia(int *img)
{
	int *sep;
	int	res;
	t_vec rgb;
	t_vec tmp;
	int		i;

	res = WIN_W * WIN_H;
	sep = (int *)malloc(res * 4);
	ft_memcpy(sep, img, res * 4);
	i = 0;
	while (i < res)
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
	ft_memcpy(img, sep, res * 4);
	free(sep);
}


img_sepia(m.img_str);
mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
