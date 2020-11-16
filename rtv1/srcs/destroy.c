/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:35:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/09 06:31:40 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	free_objects(t_rt *rt)
{
	t_obj	*next;

	while (rt && rt->objects)
	{
		next = rt->objects->next;
		free(rt->objects);
		rt->objects = next;
	}
}

static void	free_lights(t_rt *rt)
{
	t_light	*next;

	while (rt && rt->lights)
	{
		next = rt->lights->next;
		free(rt->lights);
		rt->lights = next;
	}
}

void		free_double_ptr(char ***ptr)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = *ptr;
	while (tmp && tmp[++i])
		free(tmp[i]);
	free(*ptr);
}

void		destroy(t_rt *rt, enum e_error type)
{
	free_objects(rt);
	free_lights(rt);
	rt ? free(rt->cam) : 0;
	rt ? free(rt->hit_object) : 0;
	rt && rt->m ? mlx_destroy_image(rt->m->ptr, rt->m->img) : 0;
	rt && rt->m ? mlx_clear_window(rt->m->ptr, rt->m->win) : 0;
	rt && rt->m ? mlx_destroy_window(rt->m->ptr, rt->m->win) : 0;
	rt ? free(rt->m) : 0;
	free(rt);
	ft_putstr("\033[0;31m");
	type == MALLOC_ERROR ? ft_putstr("malloc error") : 0;
	type == FILE_ERROR ? ft_putstr("UNVALID FILE") : 0;
	type == READ_FILE ? ft_putstr("READ ERROR") : 0;
	type == EMPTY_FILE ? ft_putstr("EMPTY FILE") : 0;
	type == OBJECT_UNDEFINED ? ft_putstr("OBJECT UNDEFINED") : 0;
	type == CAMERA_ERROR ? ft_putstr("CAMERA UNDEFINED") : 0;
	type == SYNTAX_ERROR ? ft_putstr("SYNTAX ERROR") : 0;
	type == OBJECT_PROPERTY ? ft_putstr("OBJECT PROPERTY ERROR") : 0;
	type == COLOR_READ ? ft_putstr("COLOR READ ERROR") : 0;
	type == GOODBYE ? ft_putstr("GOODBYE :D") : 0;
	ft_putendl("\033[0m");
	exit(0);
}

int			ft_close(t_rt *rt)
{
	destroy(rt, GOODBYE);
	return (0);
}
