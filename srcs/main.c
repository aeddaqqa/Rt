/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/26 19:30:57 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color	multip_color(t_color c1, t_color c2)
{
	t_color	new;
	float	tmp;

	tmp = c1.x * c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y * c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.z * c2.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

t_color	fraction(t_color c, double fract)
{
	t_color	new;
	double	tmp;

	tmp = c.x * fract;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.y * fract;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c.z * fract;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

int		rgb(t_color color)
{
	int		new;
	char	*ptr;

	ptr = (char *)&new;
	ptr[2] = color.x * 255;
	ptr[1] = color.y * 255;
	ptr[0] = color.z * 255;
	ptr[3] = 0;
	return (new);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	new;
	double	tmp;

	tmp = c1.x + c2.x;
	new.x = tmp > 1.0 ? 1.0 : tmp;
	tmp = c1.y + c2.y;
	new.y = tmp > 1.0 ? 1.0 : tmp;
	tmp = c2.z + c1.z;
	new.z = tmp > 1.0 ? 1.0 : tmp;
	return (new);
}

static int				in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	double		t;
	double		distance;
	t_ray		shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		if (obj != object\
				&& (t = rt->intersection[obj->type](obj, &shadow)) > 0.0)
		{
			shadow.hit_point = v_c_prod(shadow.direction, t);
			distance = sqrtf(dot(shadow.hit_point, shadow.hit_point));
			if (distance < light->d)
				return (0);
		}
		obj = obj->next;
	}
	return (1);
}

static t_color			ambient(t_object *obj, double amb)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, amb);
	color = vect_prod(color, obj->color);
	return (color);
}

static t_color			diffuse(t_light *light, double n_l, t_object *object)
{
	t_color		color;

	color = multip_color(fraction(light->color, light->intensity), object->color);
	color = fraction(color, n_l * DIFFUSE);
	return (color);
}

static t_color			specular(t_light *l, t_ray *ray, t_object *object)
{
	t_color			color;
	t_vect3		h;
	unsigned int	alpha;
	double			dot_p;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->direction, ray->direction));
	if ((dot_p = dot(object->normal, h)) <= 0)
		return (color);
	dot_p = powf(dot_p, alpha);
	color = fraction(l->color, dot_p * l->intensity * SPECULER); // TODO: specular intensity
	return (color);
}

unsigned int			light_effect(t_rt *rt, t_object *object, t_ray *ray)
{
	double			n_l;
	t_color			color[rt->nbr_lights];
	unsigned int	i;
	t_color			tmp_res[2];
	t_light			*lights;

	i = 0;
	lights = rt->lights;
	tmp_res[1] = ambient(object, rt->ambient);
	while (lights)
	{
		tmp_res[0] = (t_color){0.0, 0.0, 0.0};
		lights->direction = vect_sub(lights->position, ray->hit_point);
		lights->d = sqrtf(dot(lights->direction, lights->direction));
		lights->direction = normalize(lights->direction);
		n_l = dot(object->normal, lights->direction);
		if (n_l > 0)
			tmp_res[0] = vect_add(tmp_res[0], diffuse(lights, n_l, object));
		tmp_res[0] = add_color(tmp_res[0], specular(lights, ray, object));
		color[i++] = fraction(tmp_res[0], in_shadow(rt, lights, object));
		lights = lights->next;
	}
	while (i > 0)
		tmp_res[1] = add_color(color[--i], tmp_res[1]);
	return (rgb(tmp_res[1]));
}

int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t)
{
	ray->hit_point = vect_add(ray->origin, v_c_prod(ray->direction, t));
	ray->t = t;
	close_obj->normal = rt->normal[close_obj->type](close_obj, ray);
	return (light_effect(rt, close_obj, ray));
}

unsigned int	pixel_color(t_rt *rt, t_ray *ray)
{
	double			x;
	double			t;
	unsigned int	color;
	t_object			*close_object;
	t_object			*tmp;

	tmp = rt->objects;
	close_object = NULL;
	ray->t = -1.0;
	t = -1.0;
	color = 0;
	while (tmp)
	{
		x = rt->intersection[tmp->type](tmp, ray);
		if (x != -1 && (x < t || t == -1.0))
		{
			close_object = tmp;
			t = x;
		}
		tmp = tmp->next;
	}
	if (t != -1 && close_object)
		return (light(close_object, ray, rt, t));
		// return (0xff);
	return (0);
}

void	draw_progress_bar(t_rt *rt)
{
	int 		i;
	// int 		j;
	SDL_Rect	src;
	// int		last_time;
	int		current_time;

	src.x = W / 2 - 50;
	src.y = H / 2 - 5;
	src.w = 100;
	src.h = 10;
	SDL_SetRenderDrawColor(rt->sdl->ren_ptr, 0xEA, 0xB5, 0x43, 255);
	SDL_RenderDrawRect(rt->sdl->ren_ptr, &src);
	render(rt->sdl, rt);
	current_time = SDL_GetTicks();
	// while ((SDL_GetTicks() - current_time) < 10);
	i = 0;
}

// unsigned int lastTime = 0, currentTime;
// while (!quit) {
//   // do stuff
//   // ...

//   // Print a report once per second
//   currentTime = SDL_GetTicks();
//   if (currentTime > lastTime + 1000) {
//     printf("Report: %d\n", variable);
//     lastTime = currentTime;
//   }
// }

t_color int_to_rgb(int m)
{
	t_color rgb;

	rgb.x = (m >> 16) & 255;
	rgb.y = (m >> 8) & 255;
	rgb.z = (m & 255);
	return (rgb);
}

void draw(t_rt *rt)
{
	t_ray	*ray;
	int		y;
	int		x;
	double r1;
	double r2;
	int z;
	t_color c = {0, 0, 0};

	srand(time(0));
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			z = 0;
			c = (t_color){0, 0, 0};
			while (z < 10)
			{
			r1 = (rand() % 10) / 10.;
			r2 = (rand() % 10) / 10.;
			ray = ray_init(rt, x, y, r1, r2);
			rt->sdl->data[y * W + x] = pixel_color(rt, ray);
			c = vect_add(c, int_to_rgb(pixel_color(rt, ray)));
			free(ray);
			z++;
			}
			// draw_progress_bar(rt);
			c = v_c_prod(c, 0.1);
			c.x = (int)c.x & 255;
			c.y = (int)c.y & 255;
			c.z = (int)c.z & 255;
			rt->sdl->data[y * W + x] = rgb_to_int(c);
			x++;
		}
		y++;
	}
}

int		*init_tab()
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(4 * 6);/*free*/
	while (i < 6)
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
	while (i < 6)
	{
		tab[i] = 0;
		i++;
	}
}



void		rtrace(t_rt *rt)
{
	int		to_do;

	rt->sdl->loop = 2;
	rt->save_filter = -1;
	rt->filters = init_tab();/*free*/
	while (rt->sdl->loop)
	{
		initab(rt->filters);/*free*/
		if (rt->sdl->loop == 2)
		{
			draw(rt);
			render(rt->sdl, rt);
			menu(rt->sdl, rt->save_filter);
			rt->sdl->loop = 1;
		}
		else if (SDL_PollEvent(&rt->sdl->event))
		{
			if ((rt->sdl->event.type == SDL_WINDOWEVENT &&\
			rt->sdl->event.window.event == SDL_WINDOWEVENT_CLOSE) || rt->sdl->event.type == SDL_QUIT)
				break;
			rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
			if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
			{
				if (rt->save)
					image_create(rt->sdl->data);
				rt->sdl->loop = 0;
			}
			else if (SDL_GetMouseFocus() == rt->sdl->win_menu)
			{
				if ((to_do = re_calc(rt->sdl, rt->sdl->event)) != -1)
				{
					if (rt->save_filter == to_do)
						rt->save_filter = -1;
					else
					{
						rt->filters[to_do] = 1;
						rt->save_filter = to_do;
					}
					draw(rt);
					render(rt->sdl, rt);
				}
				menu(rt->sdl, rt->save_filter);
			}
		}
	}
	free(rt->filters);
	destroy_sdl(&rt->sdl);
}

t_object		*stock_points(int nb, char *path)
{
	t_point		tab[nb];
	t_object	*obj;
	t_object	*tmp;
	char		**split;
	char		*line;
	int			fd;
	int			i;
	int			j;
	int			z;

	i = 0;
	z = 0;
	obj = NULL;
	tmp = NULL;
	split = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#'))
			continue;
		if (z < nb)
		{
			split = ft_strsplit(line, ' ');
			j = 0;
			while (split[j])
				j++;
			if (j != 4 || ft_strcmp(split[0], "v"))
				return (NULL);
			tab[z] = (t_point){ft_atod(split[1]), ft_atod(split[2]), ft_atod(split[3])};
			z++;
		}
		else
		{
			split = ft_strsplit(line, ' ');
			j = 0;
			while (split[j])
			{
				if (j != 0)
					if (ft_atoi(split[j]) > nb || ft_atoi(split[j]) < 0)
					{
						printf("%s", split[j]);
						return (NULL);
					}
				j++;
			}
			if (!*split)
				continue;
			if (j != 4 || ft_strcmp(split[0], "f") || *line == 's' || *line == '#')
				return (NULL);
			if (!obj)
			{
				obj = (t_object*)new_object(TRIANGLE);
				obj->type = TRIANGLE;
				obj->point_a = tab[ft_atoi(split[1]) - 1];
				obj->point_b = tab[ft_atoi(split[2]) - 1];
				obj->point_c = tab[ft_atoi(split[3]) - 1];
				obj->color = (t_color){1.0, 1.0, 1.0};
				tmp = obj;
			}
			else
			{
				tmp->next = (t_object*)new_object(TRIANGLE);
				tmp->next->type = TRIANGLE;
				tmp->next->point_a = tab[ft_atoi(split[1]) - 1];
				tmp->next->point_b = tab[ft_atoi(split[2]) - 1];
				tmp->next->point_c = tab[ft_atoi(split[3]) - 1];
				tmp->next->color = (t_color){1.0, 1.0, 1.0};
				tmp = tmp->next;
			}
		}
		//  while (obj)
		//  {
		//  	printf("%lf    %lf       %lf |        ", obj->point_a.x, obj->point_a.y, obj->point_a.z);
		//  	printf("%lf    %lf       %lf |        ", obj->point_b.x, obj->point_b.y, obj->point_b.z);
		//  	printf("%lf    %lf       %lf \n", obj->point_c.x, obj->point_c.y, obj->point_c.z);
		//  	obj = obj->next;
		//  }
	}
	return (obj);
}

t_object	*load_fileobj(char *path)
{
	char	*line;
	int		fd;
	int		nb;

	nb = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#'))
			continue;
		else if (*line == 'v')
			nb++;
	}
	close(fd);
	if (!nb)
		return (NULL);
	return (stock_points(nb, path));
}


int main(int ac, char **av)
{
	char *file;
	t_rt *rt;
	char *ex;


	file = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		ex = ft_strrchr(av[1], '.');
		if (!ex)
			exit(0);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!ft_strcmp(ex, ".xml"))
		{
			if (!(file = load_file(av[1])))
				exit(0);
			if (!(parse(file, rt)))
			{
				destroy(SYNTAX_ERROR);
				free_rt(&rt);
				free(file);
				exit(0);
			}
			// t_color t = read_color("0x969696");
			// printf("color : %lf %lf %lf", rt->objects->color.x, rt->objects->color.y, rt->objects->color.x);
			// exit(0);
		}
		else if (!ft_strcmp(".obj", ex))
		{
			rt->cameras = new_object(CAMERA);
			rt->cameras->o= (t_vect3){0, 0, 2};
			rt->cameras->l= (t_vect3){0, 0, 0};
			rt->cameras->up= (t_vect3){0, 1, 0};
			rt->cameras->fov = stock_rpa(&rt->cameras->fov, "60", CAMERA);
			rt->ambient = 100;
			rt->lights = new_object(LIGHT);
			rt->lights->color = (t_vect3){1, 1, 1};
			rt->lights->position = (t_vect3){20, 10, 2.0};
			rt->lights->intensity = 100;
			rt->objects = load_fileobj(av[1]);
		}
		new_camera(rt);
		rt->sdl = init_sdl();
		new_camera(rt);
		if (rt->sdl)
			rtrace(rt);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
