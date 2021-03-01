/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:22 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/01 17:49:13 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		*convert_color(char *pixels, int w, int h , int bbp)
{
	int *data;
	int i;
	int r;
	int g;
	int b;
	int a;
	int cmp;

	data= malloc(sizeof(int) * w * h);
	i = 0;
	cmp = 0;
	while (i < w * h)
	{
		r = pixels[cmp++] & 255;
		g = pixels[cmp++] & 255;
		b = pixels[cmp++] & 255;
		if (bbp != 3)
			a = pixels[cmp++] & 255;
		data[i] = ((a << 24) | (r << 16) | (g << 8) | b);
		i++;
	}
	return (data);
}


t_sdl *init_sdl(void)
{
	t_sdl *sdl;

	SDL_Surface *s;

	if (!(s = IMG_Load("./resources/earthmap.jpg")))
		return (NULL);
	if (!(sdl = malloc(sizeof(t_sdl))))
		return (NULL);
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	sdl->font_p = TTF_OpenFont("./resources/great-vibes/GreatVibes-Regular.otf", 100);
	if (!sdl->font_p)
		return (NULL);
	sdl->font_s = TTF_OpenFont("./resources/lato/Lato-Medium.ttf", 36);
	if (!sdl->font_s)
		return (NULL);
	sdl->win_menu = SDL_CreateWindow("menu", 480, 320, 400, 800, 0);
	sdl->win_ptr = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->ren_menu = SDL_CreateRenderer(sdl->win_menu, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, W, H);
	sdl->tex = convert_color((char*)s->pixels, s->w, s->h, s->format->BytesPerPixel);
	return (sdl);
}

int				re_calc(t_sdl *sdl, SDL_Event event)
{
	int x;
	int y;
	SDL_Rect a;
	SDL_Rect b;
	SDL_Rect c;
	int i;
	
	SDL_GetMouseState(&x, &y);
	a = (SDL_Rect){x, y, 1, 1};
	i = 8;
	if (SDL_GetMouseFocus() == sdl->win_menu)
	{
		i = 0;
		while (i < 6)
		{
			b = (SDL_Rect){70, 220 + (i * 79), 260, 58};
			if (SDL_IntersectRect(&a, &b, &c) == SDL_TRUE)
				break;
			i++;
		}
	}
	if (i < 6 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		return (i);
	return (-1);
}

void			render(t_sdl *sdl, t_rt *rt)
{
	int  i;

	i = 0;
	while (i < 6)
	{
		if (rt->filters[i])
			break;
		i++;
	}
	if (i == 0)
		antialiasing(rt->sdl->data);
	if (i == 1)
		img_noise(rt->sdl->data);
	if (i == 2)
		img_sepia(rt->sdl->data);
	if (i == 3)
		img_grey(rt->sdl->data);
	if (i == 4)
		ft_cartoon(rt->sdl->data);
	if (i == 5)
		img_ddd(rt->sdl->data);
	SDL_RenderClear(sdl->ren_ptr);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->data, W * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
}

void			destroy_sdl(t_sdl **s)
{
	t_sdl *sdl;

	sdl = *s;
	// SDL_DestroyTexture(sdl->tex_menu);
	// SDL_FreeSurface(sdl->sur_menu);
	SDL_DestroyRenderer(sdl->ren_ptr);
	SDL_DestroyRenderer(sdl->ren_menu);
	SDL_DestroyWindow(sdl->win_ptr);
	SDL_DestroyWindow(sdl->win_menu);
	TTF_CloseFont(sdl->font_p);
	TTF_CloseFont(sdl->font_s);
	TTF_Quit();
	SDL_Quit();
	free(sdl);
}