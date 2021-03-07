/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:57:22 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/07 10:05:48 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		square2(int x, int save, SDL_Rect src, t_sdl *sdl)
{
	if (save < 7 && save > -1)
	{
		src.x = 70;
		src.y = (220 + save * 79);
		src.w = 260;
		src.h = 58;
		SDL_SetRenderDrawColor(sdl->ren_menu, 110, 50, 100, 0);
		SDL_RenderFillRect(sdl->ren_menu, &src);
	}
	if (x < 7)
	{
		src.x = 70;
		src.y = (220 + x * 79);
		src.w = 260;
		src.h = 58;
		SDL_SetRenderDrawColor(sdl->ren_menu, 0, 0, 0, 0);
		SDL_RenderFillRect(sdl->ren_menu, &src);
	}
}

void		square(t_sdl *sdl, int x, int save)
{
	SDL_Rect	src;
	int			i;
	int			j;

	i = 0;
	while (i < 7)
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
	square2(x, save, src, sdl);
}
