/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:39 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/22 10:58:12 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_fill3(char **tab, t_mlx *node)
{
	char **splt;

	splt = ft_strsplit(tab[4], ',');
	node->rot.x = (float)ft_atoi(splt[0]);
	node->rot.y = (float)ft_atoi(splt[1]);
	node->rot.z = (float)ft_atoi(splt[2]);
	ft_2dfree(splt);
	if (node->id == 5)
	{
		splt = ft_strsplit(tab[5], ',');
		node->nrml.x = (float)ft_atoi(splt[0]);
		node->nrml.y = (float)ft_atoi(splt[1]);
		node->nrml.z = (float)ft_atoi(splt[2]);
		ft_2dfree(splt);
	}
	return (1);
}

void	ft_fill25(char **tab, t_mlx *node, char **splt)
{
	if (node->id == 2 || node->id == 3)
		node->r = (float)ft_atoi(tab[5]);
	if (node->id == 3)
		splt = ft_strsplit(tab[6], ',');
	if (node->id == 4)
		splt = ft_strsplit(tab[5], ',');
	if (node->id == 3 || node->id == 4)
	{
		node->axis.x = (float)ft_atoi(splt[0]);
		node->axis.y = (float)ft_atoi(splt[1]);
		node->axis.z = (float)ft_atoi(splt[2]);
		ft_2dfree(splt);
	}
}

int		ft_fill2(char **tab, t_mlx *node)
{
	char	**splt;

	splt = ft_strsplit(tab[3], ',');
	node->clr.x = (float)ft_atoi(splt[0]) / 255.;
	node->clr.y = (float)ft_atoi(splt[1]) / 255.;
	node->clr.z = (float)ft_atoi(splt[2]) / 255.;
	ft_2dfree(splt);
	if (node->id == 1)
	{
		node->ntnst = (float)ft_atoi(tab[4]);
		return (1);
	}
	if (node->id == 2 || node->id == 3 || node->id == 4)
	{
		node->ang = node->id == 4 ? (float)ft_atoi(tab[6]) : 0;
		ft_fill25(tab, node, splt);
	}
	if (node->id == 2 || node->id == 3 || node->id == 4 || node->id == 5)
	{
		ft_fill3(tab, node);
		return (1);
	}
	return (0);
}

int		ft_fill(char **tab, t_mlx *node)
{
	char **splt;

	splt = ft_strsplit(tab[1], ',');
	node->pos.x = (float)ft_atoi(splt[0]);
	node->pos.y = (float)ft_atoi(splt[1]);
	node->pos.z = (float)ft_atoi(splt[2]);
	ft_2dfree(splt);
	splt = ft_strsplit(tab[2], ',');
	node->tr.x = (float)ft_atoi(splt[0]);
	node->tr.y = (float)ft_atoi(splt[1]);
	node->tr.z = (float)ft_atoi(splt[2]);
	ft_2dfree(splt);
	if (node->id == 0)
	{
		splt = ft_strsplit(tab[3], ',');
		node->dir.x = (float)ft_atoi(splt[0]);
		node->dir.y = (float)ft_atoi(splt[1]);
		node->dir.z = (float)ft_atoi(splt[2]);
		ft_2dfree(splt);
		return (1);
	}
	return (ft_fill2(tab, node));
}

void	ft_stock(char *line, t_mlx *node)
{
	char **tab;

	tab = ft_strsplit(line, '\t');
	if (ft_strcmp(tab[0], "cam") == 0)
		node->id = 0;
	else if (ft_strcmp(tab[0], "lit") == 0)
		node->id = 1;
	else if (ft_strcmp(tab[0], "sph") == 0)
		node->id = 2;
	else if (ft_strcmp(tab[0], "cyl") == 0)
		node->id = 3;
	else if (ft_strcmp(tab[0], "con") == 0)
		node->id = 4;
	else if (ft_strcmp(tab[0], "pla") == 0)
		node->id = 5;
	ft_fill(tab, node);
	node->pos = vec_add(node->pos, node->tr);
	ft_2dfree(tab);
}
