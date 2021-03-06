/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:49:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/06 16:59:56 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		next_cam(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->key_table[SDL_SCANCODE_O])
	{
		if (rt->cameras->next)
		{
			rt->cameras = rt->cameras->next;
			new_camera(rt);
			initab(rt->filters);
			if (rt->save_filter != -1)
				rt->filters[rt->save_filter] = 1;
			first_render(rt);
			menu(rt->sdl, rt->save_filter);
		}
	}
}

void		hooks(t_rt **r)
{
	t_rt	*rt;

	rt = *r;
	rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
	if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
	{
		if (rt->save)
			image_create(rt->sdl->data);
		rt->sdl->loop = 0;
	}
	next_cam(r);
	if (rt->sdl->key_table[SDL_SCANCODE_P])
	{
		if (rt->cameras->prev)
		{
			rt->cameras = rt->cameras->prev;
			new_camera(rt);
			initab(rt->filters);
			if (rt->save_filter != -1)
				rt->filters[rt->save_filter] = 1;
			first_render(rt);
			menu(rt->sdl, rt->save_filter);
		}
	}
}

void		mouse_hook(t_rt **r, int *to_do)
{
	t_rt *rt;

	rt = *r;
	if (SDL_GetMouseFocus() == rt->sdl->win_menu)
	{
		if ((*to_do = re_calc(rt->sdl, rt->sdl->event)) != -1)
		{
			if (rt->save_filter == *to_do)
				rt->save_filter = -1;
			else
			{
				rt->filters[*to_do] = 1;
				rt->save_filter = *to_do;
			}
			first_render(rt);
			render(rt->sdl, rt);
		}
		menu(rt->sdl, rt->save_filter);
	}
}
