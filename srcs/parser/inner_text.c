/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 03:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 15:15:10 by nabouzah         ###   ########.fr       */
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
	if (r == POSITION)
	{
		if ((stock_vect3(&light->position, str, r)) < 0)
			return (-1);
	}
	else if (r == COLOR)
	{
		if ((read_color(&light->color, str)) < 0)
			return (-1);
	}
	else if (r == INTENSITY)
	{
		if (stock_rpa(&light->intensity, str, r) < 0)
			return (-1);
	}
	else if (r == LOOK_AT)
	{
		if (stock_vect3(&light->look_at, str, r) < 0)
			return (-1);
	}
	else if (r == LIGHT_TYPE)
	{
		if (!ft_strcmp(str, "directional"))
			light->type = DIRECT;
		else if (!ft_strcmp(str, "parallel"))
			light->type = PARALLEL;
	}
	return (1);
}

int		*convert_color(char *pixels, int w, int h , int bbp)
{
	int *data;
	int i;
	int r;
	int g;
	int b;
	int a;
	int cmp;

	data= malloc(sizeof(int) * w * h);
	i = 0;
	cmp = 0;
	while (i < w * h)
	{
		r = pixels[cmp++] & 255;
		g = pixels[cmp++] & 255;
		b = pixels[cmp++] & 255;
		if (bbp != 3)
			a = pixels[cmp++] & 255;
		data[i] = ((a << 24) | (r << 16) | (g << 8) | b);
		i++;
	}
	return (data);
}


static void		load_texture(t_object **obj, char *str)
{
	SDL_Surface *s;
	char		*path;
	char		**split;
	int			i;

	if (!ft_strcmp(str, "checkerboard") && (*obj)->texture->type == NONE)
		(*obj)->texture->type = BOARD;
	else if (!ft_strcmp(str, "spectrum") && (*obj)->texture->type == NONE)
		(*obj)->texture->type = SPECTRUM;
	else if ((*obj)->texture->type == NONE)
	{
		split = ft_strsplit(str, ' ');
		i = 0;
		while (split[i])
		{
			if (i == 1 && !ft_strcmp("slice", split[i]))
				(*obj)->texture->slice = true;
			i++;
		}
		(*obj)->texture->type = TEX;
		path = ft_strjoin("./resources/textures/", split[0]);
		if (!path || !(s = IMG_Load(path)))
		{
			free_tab2(&split, i);
			if (path)
				free(path);
			(*obj)->texture->type = NONE;
			return ;
		}
		free(path);
		(*obj)->texture->w = s->w;
		(*obj)->texture->h = s->h;
		(*obj)->texture->data_pixels = convert_color((char*)s->pixels, s->w, s->h, s->format->BytesPerPixel);
	}
}

void			stock_slice(t_object *obj, char *str)
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

int				stock_cmp_objects(t_object *obj, int r, char *str)
{
	double		*rpa[10];
	t_vect3		*stk[12];

	stk[POSITION] = &obj->position;
	stk[POINT_A] = &obj->point_a;
	stk[POINT_B] = &obj->point_b;
	stk[POINT_C] = &obj->point_c;
	stk[POINT_D] = &obj->point_d;
	stk[CORNER_A] = &obj->corner[0];
	stk[CORNER_B] = &obj->corner[1];
	stk[ORIENTATION] = &obj->orientation;
	stk[ROTATION] = &obj->rotation;
	stk[TRANSLATION] = &obj->translation;
	rpa[ANGLE - 11] = &obj->angle;
	rpa[RADIUS - 11] = &obj->radius;
	rpa[RADIUS_1 - 11] = &obj->radius1;
	rpa[RADIUS_2 - 11] = &obj->radius2;
	rpa[HEIGHT - 11] = &obj->height;
	rpa[DISTANCE - 11] = &obj->distance;
	rpa[REFLEXION - 11] = &obj->is_ref;
	rpa[REF_INDEX - 11] = &obj->refraction_index;
	rpa[TRANSPARENT - 11] = &obj->is_transp;
	// rpa[MATTER - 11] = &obj->matter;
	if (r == SLICE)
		stock_slice(obj, str);
	else if (r < 10)
		return (stock_vect3(stk[r], str, r));
	else if (r == TEXTURE)
		load_texture(&obj, str);
	else if (r > 10)
		return (stock_rpa(rpa[r - 11], str, r));
	else
		return (read_color(&obj->color, str));
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
