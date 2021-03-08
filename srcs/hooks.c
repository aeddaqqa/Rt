/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:49:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 13:00:05 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hooks2(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->key_table[SDL_SCANCODE_F])
	{
		if (rt->hooks[0] < 1.0)
			rt->hooks[0] += 0.1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
	if (rt->sdl->key_table[SDL_SCANCODE_G])
	{
		if (rt->hooks[0] > -1.0)
			rt->hooks[0] -= 0.1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
}

void	next_cam(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->key_table[SDL_SCANCODE_O])
	{
		if (rt->cameras->next)
		{
			rt->cameras = rt->cameras->next;
			new_camera(rt);
			first_render(rt);
			menu(rt->sdl, rt->save_filter);
		}
	}
	if (rt->sdl->key_table[SDL_SCANCODE_P])
	{
		if (rt->cameras->prev)
		{
			rt->cameras = rt->cameras->prev;
			new_camera(rt);
			first_render(rt);
			menu(rt->sdl, rt->save_filter);
		}
	}
	hooks2(r);
}

void	hooks(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
	if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
	{
		if (rt->save)
			image_create(rt->sdl->data);
		rt->sdl->loop = 0;
	}
	next_cam(r);
	if (rt->sdl->key_table[SDL_SCANCODE_H])
	{
		if (rt->hooks[1] < 1.0)
			rt->hooks[1] += 0.1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
	if (rt->sdl->key_table[SDL_SCANCODE_J])
	{
		if (rt->hooks[1] > -1)
			rt->hooks[1] -= .1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
}

void	mouse_hook(t_rt **r, int *to_do)
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
