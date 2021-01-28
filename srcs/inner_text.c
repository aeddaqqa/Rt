/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/28 17:42:42 by aeddaqqa         ###   ########.fr       */
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




int				stock_cmp(void **object, char *str, int r, int type)
{
	t_vect3		*stk[11];
	t_object	*obj;
	double		*rpa[6];

	if (type == CAMERA)
		return (stock_cmp_cam(object, str, r));
	else if (type == LIGHT)
		return (stock_cmp_light(object, str, r));
	else
	{
		obj = (t_object*)object;
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
	return (1);
}


// static int		stock_cmp_obj(void **object, char *str, int r, int type)
// {
// 	t_object	*obj;

// 	obj = (t_object*)*object;
// 	obj->type = type;
// 	if (r == POSITION)
// 	{
// 		if ((get_point(str, &obj->position)) < 0)
// 			return (-1);
// 	}
// 	else if (r == COLOR)
// 	{
// 		if ((get_color(str, &obj->color)) < 0)
// 			return (-1);
// 	}
// 	else if (r == RADIUS)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->radius)) < 0)
// 			return (-1);
// 	}
// 	else if (r == ROTATION)
// 	{
// 		if ((get_ori_vect(str, &obj->rotation)) < 0)
// 			return (-1);
// 	}
// 	else if (r == TRANSLATION)
// 	{
// 		if ((get_ori_vect(str, &obj->translation)) < 0)
// 			return (-1);
// 	}
// 	else if (r == POINT_A)
// 	{
// 		if ((get_point(str, &obj->point_a)) < 0)
// 			return (-1);
// 	}
// 	else if (r == POINT_B)
// 	{
// 		if ((get_point(str, &obj->point_b)) < 0)
// 			return (-1);
// 	}
// 	else if (r == POINT_C)
// 	{
// 		if ((get_point(str, &obj->point_c)) < 0)
// 			return (-1);
// 	}
// 	else if (r == POINT_D)
// 	{
// 		if ((get_point(str, &obj->point_d)) < 0)
// 			return (-1);
// 	}
// 	else if (r == CORNER_A)
// 	{
// 		if ((get_point(str, &obj->corner[0])) < 0)
// 			return (-1);
// 	}
// 	else if (r == CORNER_B)
// 	{
// 		if ((get_point(str, &obj->corner[1])) < 0)
// 			return (-1);
// 	}
// 	else if (r == ANGLE)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->angle)) < 0)
// 			return (-1);
// 	}
// 	else if (r == DISTANCE)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->dist)) < 0)
// 			return (-1);
// 	}
// 	else if (r == RADIUS_1)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->radius1)) < 0)
// 			return (-1);
// 	}
// 	else if (r == RADIUS_2)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->radius2)) < 0)
// 			return (-1);
// 	}
// 	else if (r == HEIGHT)
// 	{
// 		if ((get_raduis_a(str, obj->type, &obj->height)) < 0)
// 			return (-1);
// 	}
// 	return (1);
// }
