void        img_rotat(int *img)
{
    int *rot;
    int res;
    int i;
    int j;
    res = WIN_W * WIN_H;
    rot = (int *)malloc(res * 4);
    ft_memcpy(rot, img, res * 4);
    j = WIN_W - 1;
    i = 0;
    while (i < res)
    {
        rot[i] = img[j];
        i++;
       if (i % WIN_W != 0 )
        j = j + WIN_W;
        else if ((i % WIN_W == 0 ) || (j + WIN_W > res))
        j = j - 1 - (WIN_W * (WIN_W - 1));
    }
    memcpy(img, rot, res * 4);
	free(rot);
}


img_rotat(m.img_str);
mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
