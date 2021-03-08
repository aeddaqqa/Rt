/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 12:42:14 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	syntax_err(t_rt *rt, char *file)
{
	destroy(SYNTAX_ERROR);
	free_rt(&rt);
	free(file);
	exit(0);
}

void	err(int ac, char **av, t_rt *rt, char *file)
{
	char *ex;

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
			syntax_err(rt, file);
	}
	else if (!ft_strcmp(".obj", ex))
	{
		if (!(parse_obj(rt, av[1])))
			exit(0);
	}
	else
		exit(EXIT_FAILURE);
	rt->sdl = init_sdl();
	new_camera(rt);
	if (rt->sdl)
		rtrace(rt);
}

int		main(int ac, char **av)
{
	char *file;
	t_rt *rt;

	file = NULL;
	rt = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		err(ac, av, rt, file);
	}
	else
		ft_putendl("./rt [fileName]");
	return (EXIT_SUCCESS);
}
