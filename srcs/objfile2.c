/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:51:27 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/08 12:51:44 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			test_obj(t_stk *w, t_point *tab, int j)
{
	if (!w->obj)
	{
		w->obj = (t_object *)new_object(TRIANGLE);
		w->obj->type = TRIANGLE;
		w->obj->point_a = tab[ft_atoi(w->split[1]) - 1];
		w->obj->point_b = tab[ft_atoi(w->split[2]) - 1];
		w->obj->point_c = tab[ft_atoi(w->split[3]) - 1];
		w->obj->color = (t_color){1.0, 1.0, 1.0};
		w->tmp = w->obj;
	}
	else
	{
		w->tmp->next = (t_object *)new_object(TRIANGLE);
		w->tmp->next->type = TRIANGLE;
		w->tmp->next->point_a = tab[ft_atoi(w->split[1]) - 1];
		w->tmp->next->point_b = tab[ft_atoi(w->split[2]) - 1];
		w->tmp->next->point_c = tab[ft_atoi(w->split[3]) - 1];
		w->tmp->next->color = (t_color){1.0, 1.0, 1.0};
		w->tmp = w->tmp->next;
		free_tab2(&w->split, j);
	}
}
