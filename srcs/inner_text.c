/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/27 18:15:19 by aeddaqqa         ###   ########.fr       */
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


int				ft_stralnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

int				stock_vect3(t_vect3 *r, char *str)
{
	char	**split;
	int		i;
	double	d[3];

	i = 0;
	split = ft_strsplit(str, " ");
	if (!split)
		return (0);
	while (split[i])
	{
		if (i > 2)
			return (0);
		if (!ft_stralnum(split[i]))//free
			return (0);
		d[i] = ft_atoi(split[i]);
		i++;
	}
	if (i != 3)
		return (-1);
	r->x = d[0];
	r->y = d[1];
	r->z = d[2];
	return (1);
}

int				stock_rpa(double *dst, char *str)
{
	if (!ft_stralnum(str))
		return (0);
	*dst = ft_atoi(str);
}

 static int  in_base(char c)
 {
	char	*lo_base;
	char	*up_base;
	int		i;

	i = 0;
	lo_base = "0123456789abcdef";
	up_base = "0123456789ABCDEF";
	if (c >= 'A' && c <= 'F')
		while (up_base[i] && up_base[i] != c)
			i++;
	else if (c >= 'a' && c <= 'f')
		while (lo_base[i] && lo_base[i] != c)
			i++;
	else if (c >= '0' && c <= '9')
		while (lo_base[i] && lo_base[i] != c)
			i++;
	else
		i = -1;
	return (i);
 }

int				rgb_to_int(t_color v)
{
	return ((((int)v.x & 0xff) << 16) | (((int)v.y & 0xff) << 8) | (int)v.z & 0xff)
}


t_color	read_color(char *data)
{
	int		color;
	int		i;
	int		hex;
	int		digit;

	 color = 0;
	if (!ft_isdigit(data[0]))
		return (to_rgb(color));
	hex = is_hex(data);
	i = hex ? 1 : -1;
	while (data && data[++i])
	{
		if	((digit = in_base(data[i])) < 0)
		{
			return ((t_color){0, 0, 0});
		}
		color = color * (hex ? 16 : 10) + digit;
	}
	return (to_rgb(color));
}

int				stock_color(t_color *color, char *str)
{
	
	return (1);
}

int				stock_cmp(void **object, char *str, int r, int type)
{
	t_vect3	**stk;
	t_object	*obj;
	double		*rpa[6];

	if (type == CAMERA)
		return (stock_cmp_cam(object, str, r));
	else if (type == LIGHT)
		return (stock_cmp_light(object, str, r));
	else
	{
		obj = (t_object*)object;
		stk = malloc(sizeof(t_vect3*) * 11);
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
			return (stock_color(&obj->color, str));
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
