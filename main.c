/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:30:29 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/01 23:23:47 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

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

void		destroy_sdl(t_sdl **s)
{
	t_sdl *sdl;

	sdl = *s;
	// SDL_DestroyTexture(sdl->tex_menu);
	// SDL_FreeSurface(sdl->sur_menu);
	SDL_DestroyRenderer(sdl->ren_ptr);
	SDL_DestroyWindow(sdl->win_ptr);
	SDL_Quit();
	free(sdl);	
}

t_sdl		*init_sdl(void)
{
	t_sdl		*sdl;
	SDL_Surface	*s;

	s = IMG_Load("earthmap.jpg");
	if (!(sdl = malloc(sizeof(t_sdl))))
		return (NULL);
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win_ptr = SDL_CreateWindow("Rt",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,W, H, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, W, H);
	sdl->tex = convert_color((char*)s->pixels, s->w, s->h, s->format->BytesPerPixel);
	sdl->data = malloc(4 * W * H);
	return (sdl);
}

void			render(t_sdl *sdl)
{
	SDL_RenderClear(sdl->ren_ptr);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->data, W * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
}

int			main(int ac, char **av)
{
	// t_sdl		*sdl;
	int			loop;
	SDL_Event	event;
	char		*key_table;
	t_rt 		rt;

	loop = 1;
	rt.cameras = malloc(sizeof(t_cam));
	rt.lights = malloc(sizeof(t_light));
	rt.objects = malloc(sizeof(t_object));
	rt.objects->position = (t_vect3){0, 0, 0};
	rt.objects->orientation = (t_vect3){0, 1, 0};
	rt.objects->color = (t_vect3){1.0, 0.0, 0.0};
	rt.objects->radius = 5;
	rt.objects->height = 0;
	rt.objects->angle = 60.0 * (M_PI / 180.0);
	rt.objects->next = NULL;
	rt.cameras->o = (t_vect3){0, 0, 30};
	rt.cameras->l = (t_vect3){0, 0, 0};
	rt.cameras->up = (t_vect3){0, 1, 0};
	rt.cameras->fov = 60.0 * (M_PI / 180.0);
	rt.cameras->next = NULL;
	rt.lights->color = (t_vect3){1.0, 1.0, 1.0};
	rt.lights->position = (t_vect3){0, 0, 10.0};
	rt.lights->intensity = 1;
	rt.lights->next = NULL;
	rt.sdl = init_sdl();
	if (rt.sdl)
	{
		while (loop)
		{
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					break;
				draw(&rt);
				render(rt.sdl);
				key_table = (char*)SDL_GetKeyboardState(NULL);
				// SDL_RenderPresent(sdl->ren_ptr);
				if (key_table[SDL_SCANCODE_ESCAPE])
					loop = 0;
			}
		}
		// destroy_sdl(&sdl);
	}
	return (EXIT_FAILURE);
}
