/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 15:15:05 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../includes/rt.h"

void		print_rt(t_rt *rrt)
{
	t_rt *rt;

	rt = rrt;
	while (rt->objects)
	{
		ft_putendl("\n[-------------------------------------------------]");
		ft_putendl("\n[---------------------Object----------------------]");
		printf("type = {%d}\n", (int)rt->objects->type);
		printf("position = {%lf,%lf,%lf}\n", rt->objects->position.x, rt->objects->position.y,rt->objects->position.z);
		printf("color = {%lf,%lf,%lf}\n",rt->objects->color.x, rt->objects->color.y, rt->objects->color.z);
		printf("orientation = {%lf,%lf,%lf}\n", rt->objects->orientation.x, rt->objects->orientation.y,rt->objects->orientation.z);
		printf("raduis = %lf\n", rt->objects->r_a);
		printf("ambient = %lf\n", rt->objects->ambient);
		ft_putendl("\n[-----------------------------------------------]");
		rt->objects = rt->objects->next;
	}
	while (rt->cameras)
	{
		ft_putendl("\n[-------------------------------------------------]");
		ft_putendl("\n[---------------------Camera----------------------]");
		printf("position = {%lf,%lf,%lf}\n", rt->cameras->o.x, rt->cameras->o.y,rt->cameras->o.z);
		printf("look-at = {%lf,%lf,%lf}\n",rt->cameras->l.x, rt->cameras->l.y, rt->cameras->l.z);
		printf("fov = %lf\n", rt->cameras->fov);
		ft_putendl("\n[-----------------------------------------------]");
		rt->cameras = rt->cameras->next;
	}
	while (rt->lights)
	{
		ft_putendl("\n[-------------------------------------------------]");
		ft_putendl("\n[---------------------Light-----------------------]");
		printf("position = {%lf,%lf,%lf}\n", rt->lights->pos.x, rt->lights->pos.y, rt->lights->pos.z);
		printf("color = {%lf,%lf,%lf}\n",rt->lights->color.x, rt->lights->color.y, rt->lights->color.z);
		printf("intensity = %lf\n", rt->lights->intensity);
		ft_putendl("\n[-----------------------------------------------]");
		rt->lights = rt->lights->next;
	}
}

static void        init_sdl(t_sdl *d)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	d->win = SDL_CreateWindow("Doom Nukem 3D",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	W, H, SDL_WINDOW_BORDERLESS);
	d->renderer = SDL_CreateRenderer(d->win, -1, 0);
	d->sdl_tex = SDL_CreateTexture(d->renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, W, H);
	d->data = malloc(sizeof(int) * W* H);
}

static void		clear_data(int *tab)
{
	int i;

	i = 0;
	while (i < W * H)
	{
		tab[i] = 0xff0000;
		i++;
	}
}

void				render(t_sdl *d)
{
	SDL_SetRenderDrawColor(d->renderer, 0, 0, 0, 255);
	SDL_RenderClear(d->renderer);
	clear_data(d->data);
	SDL_UpdateTexture(d->sdl_tex, NULL, d->data, W * 4);
	SDL_RenderCopy(d->renderer, d->sdl_tex, NULL, NULL);
	SDL_RenderPresent(d->renderer);
}

int		main(int ac, char **av)
{
	char		*file;
	int			a;
	char		*key_table;
	t_rt		*rt;
	t_sdl		sd;
	SDL_Event	event;

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
			destroy(SYNTAX_ERROR);
		print_rt(rt);
		init_sdl(&sd);
		a = 1;
		while (a)
		{
			render(&sd);
			SDL_PollEvent(&event);
			key_table = (char*)SDL_GetKeyboardState(NULL);
			if (event.type == SDL_QUIT)
				a = 0;
			if (key_table[SDL_SCANCODE_ESCAPE])
				a = 0;
		}
		free_rt(&rt);
		free(file);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}