/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:51 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/07 16:36:18 by aeddaqqa         ###   ########.fr       */
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
}
