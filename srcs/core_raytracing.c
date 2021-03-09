/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:21:03 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/09 09:20:29 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			*init_tab(void)
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(4 * 7);
	while (i < 7)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void		initab(int *tab)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		tab[i] = 0;
		i++;
	}
}

t_color		int_to_rgb(int m)
{
	t_color rgb;

	rgb.x = (m >> 16) & 255;
	rgb.y = (m >> 8) & 255;
	rgb.z = (m & 255);
	return (rgb);
}

int			core(t_rt **r)
{
	int		to_do;
	t_rt	*rt;

	rt = *r;
	to_do = 0;
	if ((rt->sdl->event.type == SDL_WINDOWEVENT &&\
	rt->sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)\
			|| rt->sdl->event.type == SDL_QUIT)
		return (0);
	hooks(r);
	mouse_hook(r, &to_do);
	return (1);
}

void		rtrace(t_rt *rt)
{
	rt->sdl->loop = 2;
	rt->save_filter = -1;
	rt->filters = init_tab();
	while (rt->sdl->loop)
	{
		initab(rt->filters);
		if (rt->sdl->loop == 2)
			first_render(rt);
		if (SDL_PollEvent(&rt->sdl->event))
		{
			if (!core(&rt))
				break ;
		}
	}
	free(rt->filters);
	destroy_sdl(&rt->sdl);
}
