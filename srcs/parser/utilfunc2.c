/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:51 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/08 16:41:55 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	new_objects2(t_object *n_obj)
{
	n_obj->type = -1;
	n_obj->position = (t_point){0, 0, 0};
	n_obj->point_a = (t_point){0, 0, 0};
	n_obj->point_b = (t_point){0, 0, 0};
	n_obj->point_c = (t_point){0, 0, 0};
	n_obj->point_d = (t_point){0, 0, 0};
	n_obj->orientation = (t_vect3){0, 0, 0};
	n_obj->rotation = (t_vect3){0, 0, 0};
	n_obj->translation = (t_vect3){0, 0, 0};
	n_obj->color = (t_color){0, 0, 0};
	n_obj->slice_axis = (t_point){0, 0, 0};
	n_obj->slice_oaxis = (t_point){0, 0, 0};
	n_obj->slice_axis_check = false;
	n_obj->slice_oaxis_check = false;
	n_obj->corner[0] = (t_point){0, 0, 0};
	n_obj->corner[1] = (t_point){0, 0, 0};
	n_obj->radius = 0;
	n_obj->radius2 = 0;
	n_obj->radius1 = 0;
	n_obj->angle = 0;
	n_obj->distance = 0;
}

void	stock_slice(t_object *obj, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i == 4)
	{
		if (!ft_strcmp(split[3], "object-axis"))
		{
			obj->slice_oaxis = (t_vect3){ft_atod(split[0]),\
			ft_atod(split[1]), ft_atod(split[2])};
			obj->slice_oaxis_check = true;
		}
		else if (!ft_strcmp(split[3], "axis"))
		{
			obj->slice_axis = (t_vect3){ft_atod(split[0]),\
			ft_atod(split[1]), ft_atod(split[2])};
			obj->slice_axis_check = true;
		}
	}
	free_tab2(&split, i);
}

int		cmp_with_objects(char *s, char **tab)
{
	int	i;

	i = 0;
	if (s)
		while (i < LIMIT_ELEMENTS + 1)
		{
			if (!ft_strcmp(s, tab[i]))
				return (i);
			i++;
		}
	return (-1);
}
