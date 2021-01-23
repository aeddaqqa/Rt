/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:28:42 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/23 18:57:26 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char					*get_tag(char *s, int *i)
{
	char	*tag;
	int		j;

	j = 0;
	if (!s || !s[j] || s[j] != '<')
		return (NULL);
	while (s[j] && s[j] != '>')
		j++;
	tag = ft_strsub(s, 0, ++j);
	*i += j;
	return (tag);
}

int						white_space(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n'))
		(*i)++;
	if (!s[*i])
		return (-1);
	return (1);
}

static t_cam			*new_cam(void)
{
	t_cam	*n_cam;

	if (!(n_cam = malloc(sizeof(t_cam))))
		return (NULL);
	n_cam->fov = -1;
	n_cam->ratio = -1;
	n_cam->plan_h = -1;
	n_cam->plan_w = -1;
	n_cam->o = (t_point){0, 0, 0};
	n_cam->l = (t_vect3){0, 0, 0};
	n_cam->up = (t_color){0, 0, 0};
	n_cam->next = NULL;
	return (n_cam);
}

static t_light			*new_light(void)
{
	t_light		*n_light;

	if (!(n_light = malloc(sizeof(t_light))))
		return (NULL);
	n_light->d = -1;
	n_light->intensity = -1;
	n_light->dir = (t_vect3){0, 0, 0};
	n_light->light_reflected = (t_vect3){0, 0, 0};
	n_light->color = (t_color){0, 0, 0};
	n_light->pos = (t_point){0, 0, 0};
	n_light->next = NULL;
	return (n_light);
}

void					*new_object(int type)
{
	t_object	*n_obj;

	n_obj = NULL;
	if (type == CAMERA)
		return (new_cam());
	else if (type == LIGHT)
		return (new_light());
	else
	{
		if (!(n_obj = malloc(sizeof(t_object))))
			return (NULL);
		n_obj->type = -1;
		n_obj->position = (t_point){0, 0, 0};
		n_obj->point_a = (t_point){0, 0, 0};
		n_obj->point_b = (t_point){0, 0, 0};
		n_obj->point_c = (t_point){0, 0, 0};
		n_obj->point_d = (t_point){0, 0, 0};
		n_obj->corner[0] = (t_point){0, 0, 0};
		n_obj->corner[1] = (t_point){0, 0, 0};
		n_obj->orientation = (t_vect3){0, 0, 0};
		n_obj->rotation = (t_vect3){0, 0, 0};
		n_obj->translation = (t_vect3){0, 0, 0};
		n_obj->color = (t_color){0, 0, 0};
		n_obj->radius = 0;
		n_obj->radius2 = 0;
		n_obj->radius1 = 0;
		n_obj->angle = 0;
		n_obj->next = NULL;
		return (n_obj);
	}
	return (NULL);
}
