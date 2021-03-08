/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 16:44:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

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
		if ((stock_vect3(&cam->o, str, r)) < 0)
			return (-1);
	}
	else if (r == LOOK_AT)
	{
		if ((stock_vect3(&cam->l, str, r)) < 0)
			return (-1);
	}
	else if (r == FOV)
	{
		if (stock_rpa(&cam->fov, str, r) < 0)
			return (-1);
	}
	return (1);
}

static	int		stock_cmp_light(void **object, char *str, int r)
{
	t_light		*light;

	light = (t_light*)*object;
	if ((r == POSITION) && ((stock_vect3(&light->position, str, r)) < 0))
		return (-1);
	else if ((r == COLOR) && ((read_color(&light->color, str)) < 0))
		return (-1);
	else if ((r == INTENSITY) && (stock_rpa(&light->intensity, str, r) < 0))
		return (-1);
	else if ((r == LOOK_AT) && (stock_vect3(&light->look_at, str, r) < 0))
		return (-1);
	else if (r == LIGHT_TYPE)
	{
		if (!ft_strcmp(str, "directional"))
			light->type = DIRECT;
		else if (!ft_strcmp(str, "parallel"))
			light->type = PARALLEL;
	}
	return (1);
}

int				stock_cmp(void **object, char *str, int r, int type)
{
	t_object *obj;

	if (type == CAMERA)
		return (stock_cmp_cam(object, str, r));
	else if (type == LIGHT)
		return (stock_cmp_light(object, str, r));
	else
	{
		obj = (t_object*)*object;
		return (stock_cmp_objects(obj, r, str));
	}
	return (1);
}
