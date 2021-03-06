/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/06 04:23:32 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int	main(int ac, char **av)
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
		}
		else if (!ft_strcmp(".obj", ex))
		{
			if (!(parse_obj(rt, av[1])))
				exit(0);
		}
		else
			exit(EXIT_FAILURE);
		rt->sdl = init_sdl();
		rt->objects->is_transp = 1;
		rt->objects->is_ref = 0;
		rt->objects->refraction_index = 0;
		rt->objects->next->is_transp = 0;
		rt->objects->next->is_ref = 0;
		rt->objects->next->refraction_index = 0;
		new_camera(rt);
		if (rt->sdl)
			rtrace(rt);
	}
	else
		ft_putendl("./rt [fileName]");
	return (EXIT_SUCCESS);
}
