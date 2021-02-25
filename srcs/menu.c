/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:18 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/25 14:54:42 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void title(t_sdl *sdl)
{
	int tex_x;
	int tex_y;
	SDL_Rect dstrect;
	SDL_Texture *tex;
	SDL_Surface *sur;

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

static void square(t_sdl *sdl, int x, int save)
{
	SDL_Rect src;
	int i;
	int j;

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
	if (save < 6 && save > -1)
	{
		src.x = 70;
		src.y = (220 + save * 79);
		src.w = 260;
		src.h = 58;
		SDL_SetRenderDrawColor(sdl->ren_menu, 110, 50, 100, 0);
		SDL_RenderFillRect(sdl->ren_menu, &src);
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

static void		elements(t_sdl *sdl, int x)
{
	int i;
	int tex_x;
	int tex_y;
	SDL_Rect dstrect;
	SDL_Texture *tex;
	SDL_Surface *sur;
	char *tab[6];
	SDL_Color color;

	i = 0;
	tab[0] = (char *)"Antiliasing";
	tab[1] = (char *)"Noise";
	tab[2] = (char *)"Sepia";
	tab[3] = (char *)"Grey";
	tab[4] = (char *)"Cartoon";
	tab[5] = (char *)"Stereoscopy"; //EAB543
	while (i < 6)
	{
		tex_x = 0;
		tex_y = 0;
		color = (x == i) ? (SDL_Color){0xff, 0xff, 0xff, 0xff} : (SDL_Color)FONT_S;
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

// static void		load_button(t_sdl *sdl)
// {
// 	SDL_Rect src;
// 	int tex_x;
// 	int tex_y;
// 	SDL_Rect dstrect;
// 	SDL_Texture *tex;
// 	SDL_Surface *sur;
// 	// SDL_Surface *rect;

// 	src.x = 114;
// 	src.y = 685;
// 	src.w = 172;
// 	src.h = 55;
// 	SDL_SetRenderDrawColor(sdl->ren_menu, 0xff, 0xff, 0xff, 255);
// 	SDL_RenderFillRect(sdl->ren_menu, &src);
// 	tex_x = 0;
// 	tex_y = 0;
// 	sur = TTF_RenderText_Blended(sdl->font_s, "Load", (SDL_Color){0, 0, 0, 0xff});
// 	if (!sur)
// 		exit(1);
// 	tex = SDL_CreateTextureFromSurface(sdl->ren_menu, sur);
// 	if (!tex)
// 		exit(1);
// 	SDL_QueryTexture(tex, NULL, NULL, &tex_x, &tex_y);
// 	dstrect = (SDL_Rect){160, 690, tex_x, tex_y};
// 	SDL_SetTextureAlphaMod(tex, 255);
// 	SDL_RenderCopy(sdl->ren_menu, tex, NULL, &dstrect);
// 	SDL_FreeSurface(sur);
// 	SDL_DestroyTexture(tex);
// }

void menu(t_sdl *sdl, int save)
{
	int x;
	int y;
	SDL_Rect a;
	SDL_Rect b;
	SDL_Rect c;
	int i;

	// SDL_SetRenderDrawBlendMode(sdl->ren_menu, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(sdl->ren_menu, 0x18, 0x2c, 0x61, 255);
	SDL_RenderClear(sdl->ren_menu);
	title(sdl);
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
	// if (i < 6 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	// 	printf("%d", i);
	square(sdl, i, save);
	elements(sdl, i);
	// load_button(sdl);
	SDL_RenderPresent(sdl->ren_menu);
}