/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:18 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/07 12:30:58 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		title(t_sdl *sdl)
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

int				init_arr(char **tab)
{
	tab[0] = (char *)"Antiliasing";
	tab[1] = (char *)"Noise";
	tab[2] = (char *)"Sepia";
	tab[3] = (char *)"Grey";
	tab[4] = (char *)"Cartoon";
	tab[5] = (char *)"Stereoscopy";
	tab[6] = (char *)"Blur";
	return (0);
}

static void		elements(t_sdl *sdl, int x)
{
	t_tx		t;
	t_rts		z;
	char		*tab[7];
	SDL_Color	color;

	t.i = init_arr(tab);
	while (t.i < 7)
	{
		t.tex_x = 0;
		t.tex_y = 0;
		color = (x == t.i) ? (SDL_Color){0xff, 0xff, 0xff, 0xff} : \
				(SDL_Color)FONT_S;
		z.sur = TTF_RenderText_Blended(sdl->font_s, tab[t.i], color);
		if (!z.sur)
			exit(1);
		z.tex = SDL_CreateTextureFromSurface(sdl->ren_menu, z.sur);
		if (!z.tex)
			exit(1);
		SDL_QueryTexture(z.tex, NULL, NULL, &t.tex_x, &t.tex_y);
		z.dstrect = (SDL_Rect){107, 224 + (t.i * 79), t.tex_x, t.tex_y};
		SDL_RenderCopy(sdl->ren_menu, z.tex, NULL, &z.dstrect);
		SDL_FreeSurface(z.sur);
		SDL_DestroyTexture(z.tex);
		t.i++;
	}
}

void			menu(t_sdl *sdl, int save)
{
	int			x;
	int			y;
	t_rect		z;
	int			i;

	SDL_SetRenderDrawColor(sdl->ren_menu, 0x18, 0x2c, 0x61, 255);
	SDL_RenderClear(sdl->ren_menu);
	title(sdl);
	SDL_GetMouseState(&x, &y);
	z.a = (SDL_Rect){x, y, 1, 1};
	i = 8;
	if (SDL_GetMouseFocus() == sdl->win_menu)
	{
		i = 0;
		while (i < 7)
		{
			z.b = (SDL_Rect){70, 220 + (i * 79), 260, 58};
			if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE)
				break ;
			i++;
		}
	}
	square(sdl, i, save);
	elements(sdl, i);
	SDL_RenderPresent(sdl->ren_menu);
}
