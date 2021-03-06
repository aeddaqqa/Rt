/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:49:32 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/06 17:02:47 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		draw_first_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x, y);
			x++;
		}
		y++;
	}
}

static void		draw_second_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 400;
	while (y < 800)
	{
		x = 0;
		while (x < 400)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x, y);
			x++;
		}
		y++;
	}
}

static void		draw_third_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 0;
	while (y < 400)
	{
		x = 400;
		while (x < 800)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x, y);
			x++;
		}
		y++;
	}
}

static void		draw_fourth_thread(t_rt *rt)
{
	int		y;
	int		x;

	srand(time(0));
	y = 400;
	while (y < 800)
	{
		x = 400;
		while (x < 800)
		{
			if (rt->filters[0])
				apply_antiliasing(rt, x, y);
			else
				draw_scene(rt, x, y);
			x++;
		}
		y++;
	}
}

void			first_render(t_rt *rt)
{
	SDL_Thread	*tab[4];
	int			thread_return_value[4];

	tab[0] = SDL_CreateThread((SDL_ThreadFunction)draw_first_thread,\
			"draw_first_thread", (void *)rt);
	tab[1] = SDL_CreateThread((SDL_ThreadFunction)draw_second_thread,\
			"draw_second_thread", (void *)rt);
	tab[2] = SDL_CreateThread((SDL_ThreadFunction)draw_third_thread,\
			"draw_third_thread", (void *)rt);
	tab[3] = SDL_CreateThread((SDL_ThreadFunction)draw_fourth_thread,\
			"draw_fourth_thread", (void *)rt);
	SDL_WaitThread(tab[0], &thread_return_value[0]);
	SDL_WaitThread(tab[1], &thread_return_value[1]);
	SDL_WaitThread(tab[2], &thread_return_value[2]);
	SDL_WaitThread(tab[3], &thread_return_value[3]);
	render(rt->sdl, rt);
	menu(rt->sdl, rt->save_filter);
	rt->sdl->loop = 1;
}
