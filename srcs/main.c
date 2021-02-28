/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/28 17:54:28 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
		}
		else if (!ft_strcmp(".obj", ex))
			parse_obj(rt, av[1]);
		// while (rt->cameras->next)
		// {
		// 	// printf("\n(%lf, %f, %lf)\n", rt->cameras->o.x, rt->cameras->o.y, rt->cameras->o.z);
		// 	rt->cameras = rt->cameras->next;
		// }
		// // printf("\n(%lf, %f, %lf)\n", rt->cameras->o.x, rt->cameras->o.y, rt->cameras->o.z);
		// while (rt->cameras->prev)
		// {
		// 	printf("\n(%lf, %f, %lf)\n", rt->cameras->o.x, rt->cameras->o.y, rt->cameras->o.z);
		// 	rt->cameras = rt->cameras->prev;
		// }
		// printf("\n(%lf, %f, %lf)\n", rt->cameras->o.x, rt->cameras->o.y, rt->cameras->o.z);
		// exit(0);
		rt->sdl = init_sdl();
		new_camera(rt);
		if (rt->sdl)
			rtrace(rt);
	}
	else
		ft_putendl("./rt [fileName]");
	return (EXIT_SUCCESS);
}
