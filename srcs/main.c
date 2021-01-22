/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/22 15:33:38 by aeddaqqa         ###   ########.fr       */
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
		// printf("raduis = %lf\n", rt->objects->r_a);
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

int		main(int ac, char **av)
{
	char	*file;
	t_rt	*rt;

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
		free_rt(&rt);
		free(file);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
