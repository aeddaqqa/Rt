void        img_noise(int *img)
{
	int	*noi;
	int	*noimag;
	int	i;
	int	*grey;
	int r;
	t_vec rgb;

	srand(time(0));
	i = 0;
	grey = (int*)malloc(sizeof(int) * 4);
	noi = (int*)malloc(sizeof(int) * WIN_W * WIN_H * 4);
	noimag = (int*)malloc(sizeof(int) * WIN_W * WIN_H * 4);
	grey[0] = 2631720;
	grey[1] = 1973790;
	grey[2] = 1315860;
	while (i < WIN_W * WIN_H)
	{
		r = (rand() % 3);
		noi[i] = grey[r];
		i++;
	}
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		rgb.x = ((img[i] >> 16) * 3 + (noi[i] >> 16)) / 4;
		rgb.y = (((img[i] >> 8) % 256) * 3 + ((noi[i] >> 8) % 256)) / 4;
		rgb.z = ((img[i] % 256) * 3 + (noi[i] % 256)) / 4;
		noimag[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
	ft_memcpy(img, noimag, WIN_W * WIN_H * 4);
	free(grey);
	free(noi);
	free(noimag);
}

img_noise(m.img_str);
mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
