/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:30:29 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/02 10:50:11 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SDL2.framework/Headers/SDL.h"
#include "./SDL2_image.framework/Headers/SDL_image.h"
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"

#define W 800
#define H 800
#define COLOR_1 0x192a56
#define COLOR_2 0xfbc531
#define COLOR_3 0xf5f6fa
#define COLOR_4 0x2f3640
#define FONT_P {0xea, 0xb5, 0x43}
#define FONT_S {0xF8, 0xEF, 0xBA}


typedef struct		s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Window		*win_menu;
	SDL_Renderer	*ren_ptr;
	SDL_Renderer	*ren_menu;
	TTF_Font		*font_p;
	TTF_Font		*font_s;
}					t_sdl;

void		destroy_sdl(t_sdl **s)
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

t_sdl		*init_sdl(void)
{
	t_sdl *sdl;

	if (!(sdl = malloc(sizeof(t_sdl))))
		return (NULL);
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	sdl->font_p = TTF_OpenFont("./great-vibes/GreatVibes-Regular.otf", 100);
	if (!sdl->font_p)
		return (NULL);
	sdl->font_s = TTF_OpenFont("./lato/Lato-Medium.ttf", 36);
	if (!sdl->font_s)
		return (NULL);
	sdl->win_menu = SDL_CreateWindow("menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 800, 0);
	sdl->win_ptr = SDL_CreateWindow("Rt",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,W, H, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->ren_menu = SDL_CreateRenderer(sdl->win_menu, -1, 0);
	return (sdl);
}

void		title(t_sdl *sdl)
{
	int			tex_x;
	int			tex_y;
	SDL_Rect	dstrect;
	SDL_Texture	*tex;
	SDL_Surface	*sur;

	tex_x = 0;
	tex_y = 0;
	sur = TTF_RenderText_Blended(sdl->font_p, "RT", (SDL_Color)FONT_P);
	if (!sur)
		exit(1);
	tex = SDL_CreateTextureFromSurface(sdl->ren_menu, sur);
	if (!tex)
		exit(1);
	SDL_QueryTexture(tex, NULL, NULL, &tex_x, &tex_y);
	dstrect = (SDL_Rect){90, 75, tex_x, tex_y};
	SDL_RenderCopy(sdl->ren_menu, tex, NULL, &dstrect);
	SDL_FreeSurface(sur);
	SDL_DestroyTexture(tex);
}

// EAB543

void		square(t_sdl *sdl, int x)
{
	SDL_Rect	src;
	int			i;
	int			j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 3)
		{
			src.x = 70 - j;
			src.y = (220 + i * 79) - j;
			src.w = 260 + (2 * j);
			src.h = 58 + (2 * j);
			SDL_SetRenderDrawColor(sdl->ren_menu, 0xEA, 0xB5, 0x43, 255);
			SDL_RenderDrawRect(sdl->ren_menu, &src);
			j++;
		}
		i++;
	}
	if (x < 6)
	{
		src.x = 70;
		src.y = (220 + x * 79);
		src.w = 260;
		src.h = 58;
		SDL_SetRenderDrawColor(sdl->ren_menu, 0, 0, 0, 0);
		SDL_RenderFillRect(sdl->ren_menu, &src);
	}
}

void		elements(t_sdl *sdl, int x)
{
	int			i;
	int			tex_x;
	int			tex_y;
	SDL_Rect	dstrect;
	SDL_Texture	*tex;
	SDL_Surface	*sur;
	char 		*tab[6];
	SDL_Color	color;

	i = 0;
	tab[0] = (char *)"Antiliasing";
	tab[1] = (char *)"Noise";
	tab[2] = (char *)"Sepia";
	tab[3] = (char *)"Grey";
	tab[4] = (char *)"Cartoon";
	tab[5] = (char *)"Stereoscopy";//EAB543
	while (i < 6)
	{
		tex_x = 0;
		tex_y = 0;
		color = (x == i) ? (SDL_Color){0xff, 0xff, 0xff} : (SDL_Color)FONT_S;
		sur = TTF_RenderText_Blended(sdl->font_s, tab[i], color);
		if (!sur)
			exit(1);
		tex = SDL_CreateTextureFromSurface(sdl->ren_menu, sur);
		if (!tex)
			exit(1);
		SDL_QueryTexture(tex, NULL, NULL, &tex_x, &tex_y);
		dstrect = (SDL_Rect){107, 224 + (i * 79), tex_x, tex_y};
		SDL_RenderCopy(sdl->ren_menu, tex, NULL, &dstrect);
		SDL_FreeSurface(sur);
		SDL_DestroyTexture(tex);
		i++;
	}
}

void		load_button(t_sdl *sdl)
{
	SDL_Rect src;
	int			tex_x;
	int			tex_y;
	SDL_Rect	dstrect;
	SDL_Texture	*tex;
	SDL_Surface	*sur;
	SDL_Surface	*rect;

	src.x = 114;
	src.y = 685;
	src.w = 172;
	src.h = 55;
	SDL_SetRenderDrawColor(sdl->ren_menu, 0xff, 0xff, 0xff, 255);
	SDL_RenderFillRect(sdl->ren_menu, &src);
	tex_x = 0;
	tex_y = 0;
	sur = TTF_RenderText_Blended(sdl->font_s, "Load", (SDL_Color){0, 0, 0});
	if (!sur)
		exit(1);
	tex = SDL_CreateTextureFromSurface(sdl->ren_menu, sur);
	if (!tex)
		exit(1);
	SDL_QueryTexture(tex, NULL, NULL, &tex_x, &tex_y);
	dstrect = (SDL_Rect){160, 690, tex_x, tex_y};
	SDL_SetTextureAlphaMod(tex, 255);
	SDL_RenderCopy(sdl->ren_menu, tex, NULL, &dstrect);
	SDL_FreeSurface(sur);
	SDL_DestroyTexture(tex);
}

void		menu(t_sdl *sdl, SDL_Event event)
{
	int			x;
	int			y;
	SDL_Rect	a;
	SDL_Rect	b;
	SDL_Rect	c;
	int			i;

	// SDL_SetRenderDrawBlendMode(sdl->ren_menu, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(sdl->ren_menu, 0x18, 0x2c, 0x61, 255);
	SDL_RenderClear(sdl->ren_menu);
	title(sdl);
	SDL_GetMouseState(&x, &y);
	a.x = x;
	a.y = y;
	a.w = 1;
	a.h = 1;
	i = 8;
	if (SDL_GetMouseFocus() == sdl->win_menu)
	{
		i = 0;
		while (i < 6)
		{
			b.x = 70;
			b.y = 220 + (i * 79);
			b.w = 260;
			b.h = 58;
			if (SDL_IntersectRect(&a, &b, &c) == SDL_TRUE)
				break;
			i++;
		}
	}
	if (i < 6 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		printf("%d", i);
	square(sdl, i);
	elements(sdl, i);
	load_button(sdl);
	SDL_RenderPresent(sdl->ren_menu);
}

int			main(int ac, char **av)
{
	t_sdl		*sdl;
	int			loop;
	SDL_Event	event;
	char		*key_table;

	loop = 1;
	sdl = init_sdl();
	if (sdl)
	{
		while (loop)
		{
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					break;
				key_table = (char*)SDL_GetKeyboardState(NULL);
				menu(sdl, event);
				SDL_RenderPresent(sdl->ren_ptr);
				if (key_table[SDL_SCANCODE_ESCAPE])
					loop = 0;
			}
		}
		destroy_sdl(&sdl);
	}
	return (EXIT_FAILURE);
}