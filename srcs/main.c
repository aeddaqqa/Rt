/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/21 19:01:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_mlx *init_mlx(t_rt *rt)
{
	t_mlx *new;

	if (!(new = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		free_rt(&rt);
		return (NULL);
	}
	new->ptr = mlx_init();
	new->win = mlx_new_window(new->ptr, W, H, "RT");
	new->img = mlx_new_image(new->ptr, W, H);
	new->data = (int *)mlx_get_data_addr(new->img, &new->bpp,
										 &new->ls, &new->end);
	return (new);
}

int raycast(t_object *lst, t_ray ray, t_hit *hit)
{
	t_object *p;
	double t;
	t_ray save;

	t = INFINITY;
	hit->object = NULL;
	hit->t = INFINITY;
	p = lst;
	save = obj_intersect(p, hit, ray, t);
	if (hit->object == NULL)
		return (0);
	hit->p = vect_add(save.origin, v_c_prod(save.direction, hit->t));
	ft_compute_normals(hit, &save);
	return (1);
}

t_color raytrace(t_rt *rt, t_hit *hit, t_ray *ray)
{
	t_color	ret;

	ret = (t_color){0, 0, 0};
	if (raycast(rt->objects, *ray, hit))
		ret = ft_shade_object(hit, rt, ray);
	return (ret);
}

void draw(t_rt *rt)
{
	t_ray *ray;
	t_hit hit;
	int y;
	int x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ray = ray_init(rt, x, y);
			hit.t = INFINITY;
			if (raycast(rt->objects, *ray, &hit))
			{
				rt->sdl->data[y * W + x] = rgb_to_int(raytrace(rt, &hit, ray));
				// rt->mlx->data[y * W + x] = 0xff0000;
			}
			x++;
		}
		y++;
	}
}

t_sdl *init_sdl(void)
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
	sdl->win_ptr = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->ren_menu = SDL_CreateRenderer(sdl->win_menu, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, W, H);
	return (sdl);
}

void title(t_sdl *sdl)
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

// EAB543

void square(t_sdl *sdl, int x)
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

void elements(t_sdl *sdl, int x)
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

void load_button(t_sdl *sdl)
{
	SDL_Rect src;
	int tex_x;
	int tex_y;
	SDL_Rect dstrect;
	SDL_Texture *tex;
	SDL_Surface *sur;
	// SDL_Surface *rect;

	src.x = 114;
	src.y = 685;
	src.w = 172;
	src.h = 55;
	SDL_SetRenderDrawColor(sdl->ren_menu, 0xff, 0xff, 0xff, 255);
	SDL_RenderFillRect(sdl->ren_menu, &src);
	tex_x = 0;
	tex_y = 0;
	sur = TTF_RenderText_Blended(sdl->font_s, "Load", (SDL_Color){0, 0, 0, 0xff});
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

void destroy_sdl(t_sdl **s)
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

void menu(t_sdl *sdl, SDL_Event event)
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

void				render(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->data, W * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	// SDL_SetRenderDrawColor(d->sdl.ren_ptr, 255, 255, 255, 0);
	SDL_RenderPresent(sdl->ren_ptr);
}

int main(int ac, char **av)
{
	char *file;
	t_rt *rt;

	file = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		if (!(file = load_file(av[1])))
			exit(0);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!(parse(file, rt)))
		{
			destroy(SYNTAX_ERROR);
			free_rt(&rt);
			free(file);
			exit(0);
		}
		rt->sdl = init_sdl();
		rt->sdl->loop = 1;
		if (rt->sdl)
		{
			while (rt->sdl->loop)
			{
				if (SDL_PollEvent(&rt->sdl->event))
				{
					 if (rt->sdl->event.type == SDL_WINDOWEVENT && rt->sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
					 	break;
					rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
					cam_cord_system(rt->cameras);
					draw(rt);
					menu(rt->sdl, rt->sdl->event);
					SDL_RenderPresent(rt->sdl->ren_ptr);
					render(rt->sdl);
					if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
						rt->sdl->loop = 0;
				}
			}
			destroy_sdl(&rt->sdl);
		}
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
