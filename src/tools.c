/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:39:49 by chzabakh          #+#    #+#             */
/*   Updated: 2020/10/21 10:44:40 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_2dfree(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_lstrmv(t_mlx **head)
{
	t_mlx	*next;

	while (*head)
	{
		if ((*head)->next)
			next = (*head)->next;
		free(*head);
		*head = next;
	}
}

t_vec	x_rotation(t_vec v, float theta)
{
	t_vec	result;

	theta = convert(theta);
	result = v;
	result.y = v.y * cos(theta) + v.z * -sin(theta);
	result.z = v.y * sin(theta) + v.z * cos(theta);
	return (result);
}

t_vec	y_rotation(t_vec v, float theta)
{
	t_vec	result;

	theta = convert(theta);
	result = v;
	result.x = v.x * cos(theta) + v.z * sin(theta);
	result.z = v.x * -sin(theta) + v.z * cos(theta);
	return (result);
}

t_vec	z_rotation(t_vec v, float theta)
{
	t_vec	result;

	theta = convert(theta);
	result = v;
	result.x = v.x * cos(theta) + v.y * -sin(theta);
	result.y = v.x * sin(theta) + v.y * cos(theta);
	return (result);
}
