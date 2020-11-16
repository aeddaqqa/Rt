/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:38:30 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/24 09:23:54 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_usage(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./rtv1 [scene]");
		exit(0);
	}
}

void	ft_camchk(t_mlx *head)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->id == 0)
			i++;
		head = head->next;
	}
	if (i != 1)
	{
		ft_lstrmv(&head);
		ft_putendl("cam error");
		exit(0);
	}
}

void	checkline(char *line)
{
	if (ft_check(line) == 0)
	{
		ft_putendl("syntax error!\n");
		exit(0);
	}
}

t_main	ft_list(t_main z)
{
	if (!z.head)
	{
		z.head = (t_mlx*)malloc(sizeof(t_mlx));
		z.tmp = z.head;
	}
	else
	{
		z.tmp->next = (t_mlx*)malloc(sizeof(t_mlx));
		z.tmp = z.tmp->next;
	}
	return (z);
}

int		main(int argc, char **argv)
{
	t_main	z;

	ft_usage(argc);
	z.fd = open(argv[1], O_RDONLY);
	z.head = NULL;
	z.tmp = NULL;
	while (get_next_line(z.fd, &z.line) > 0)
	{
		if (z.line[0] != '#')
		{
			checkline(z.line);
			z = ft_list(z);
			ft_stock(z.line, z.tmp);
			z.tmp->next = NULL;
		}
		free(z.line);
	}
	ft_camchk(z.head);
	ft_start(z.head);
	ft_lstrmv(&z.head);
	close(z.fd);
	return (0);
}
