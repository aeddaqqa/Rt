/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/22 17:24:17 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char			*inner_text(char *s, int *j)
{
	char	*new;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '<')
		i++;
	if (!s[i])
		return (NULL);
	new = ft_strsub(s, 0, i);
	*j += i;
	return (new);
}

static int		stock_cmp_cam(void **object, char *str, int r)
{
	t_cam		*cam;

	cam = (t_cam*)*object;
	if (r == ORIGIN)
	{
		if ((get_point(str, &cam->o)) < 0)
			return (-1);
	}
	else if (r == LOOK_AT)
	{
		if ((get_point(str, &cam->l)) < 0)
			return (-1);
	}
	else if (r == FOV)
		cam->fov = ft_atoi(str);
	return (1);
}

static	int		stock_cmp_light(void **object, char *str, int r)
{
	t_light		*light;

	light = (t_light*)*object;
	if (r == POSITION)
	{
		if ((get_point(str, &light->pos)) < 0)
			return (-1);
	}
	else if (r == COLOR)
	{
		if ((get_color(str, &light->color)) < 0)
			return (-1);
	}
	else if (r == INTENSITY)
		light->intensity = ft_atoi(str);
	return (1);
}

static int		stock_cmp_obj(void **object, char *str, int r, int type)
{
	t_object	*obj;

	obj = (t_object*)*object;
	obj->type = type;
	if (r == POSITION)
	{
		if ((get_point(str, &obj->position)) < 0)
			return (-1);
	}
	else if (r == COLOR)
	{
		if ((get_color(str, &obj->color)) < 0)
			return (-1);
	}
	else if (r == RADIUS)
	{
		if ((get_raduis_a(str, obj->type, &obj->raduis)) < 0)
			return (-1);
	}
	else if (r == ROTATION)
	{
		if ((get_ori_vect(str, &obj->rotation)) < 0)
			return (-1);
	}
	else if (r == TRANSITION)
	{
		if ((get_ori_vect(str, &obj->orientation)) < 0)
			return (-1);
	}
	return (1);
}

int				stock_cmp(void **object, char *str, int r, int type)
{
	if (type == CAMERA)
		return (stock_cmp_cam(object, str, r));
	else if (type == LIGHT)
		return (stock_cmp_light(object, str, r));
	else
		return (stock_cmp_obj(object, str, r, type));
	return (1);
}
