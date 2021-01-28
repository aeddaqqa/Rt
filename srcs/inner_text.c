/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/28 18:42:53 by aeddaqqa         ###   ########.fr       */
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
		if ((stock_vect3(&cam->o, str)) < 0)
			return (-1);
	}
	else if (r == LOOK_AT)
	{
		if ((stock_vect3(&cam->l, str)) < 0)
			return (-1);
	}
	else if (r == FOV)
	{
		if (stock_rpa(&cam->fov ,str) < 0)
			return (-1);
	}
	return (1);
}

static	int		stock_cmp_light(void **object, char *str, int r)
{
	t_light		*light;

	light = (t_light*)*object;
	if (r == POSITION)
	{
		if ((stock_vect3(&light->pos, str)) < 0)
			return (-1);
	}
	else if (r == COLOR)
	{
		if ((read_color(&light->color, str)) < 0)
			return (-1);
	}
	else if (r == INTENSITY)
	{
		if (stock_rpa(&light->intensity , str) < 0)
			return (-1);
	}
	return (1);
}


int				stock_cmp_objects(void **object, int r, char *str)
{
	t_object	*obj;
	double		*rpa[6];
	t_vect3		*stk[11];
	
	obj = (t_object*)*object;
	stk[POSITION] =  &obj->position;
	stk[POINT_A] =  &obj->point_a;
	stk[POINT_B] =  &obj->point_b;
	stk[POINT_C] =  &obj->point_c;
	stk[POINT_D] =  &obj->point_d;
	stk[CORNER_A] =  &obj->corner[0];
	stk[CORNER_B] =  &obj->corner[1];
	stk[ORIENTATION] =  &obj->orientation;
	stk[ROTATION] =  &obj->rotation;
	stk[TRANSLATION] =  &obj->translation;
	rpa[ANGLE - 11] = &obj->angle;
	rpa[RADIUS - 11] = &obj->radius;
	rpa[RADIUS_1 - 11] = &obj->radius1;
	rpa[RADIUS_2 - 11] = &obj->radius2;
	rpa[HEIGHT - 11] = &obj->height;
	rpa[DISTANCE - 11] = &obj->dist;
	stk[10] = NULL;
	if (r < 10)
		return (stock_vect3(stk[r], str));
	else if (r > 10)
		return (stock_rpa(rpa[r - 11], str));
	else
		return (read_color(&obj->color, str));
}
int				stock_cmp(void **object, char *str, int r, int type)
{

	if (type == CAMERA)
		return (stock_cmp_cam(object, str, r));
	else if (type == LIGHT)
		return (stock_cmp_light(object, str, r));
	else
		return (stock_cmp_objects(object, r, str));
	return (1);
}