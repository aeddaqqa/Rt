/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:24:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/08 18:32:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

/*
** **********************************************************************
** 	int r; -> color[0]
** 	int g; -> color[1]
** 	int b; -> color[2]
** 	int a; -> color[3]
*/

int				*convert_color(char *pixels, int w, int h, int bbp)
{
	int i;
	int cmp;
	int *data;
	int col[4];

	data = malloc(sizeof(int) * w * h);
	i = 0;
	cmp = 0;
	while (i < w * h)
	{
		col[0] = pixels[cmp++] & 255;
		col[1] = pixels[cmp++] & 255;
		col[2] = pixels[cmp++] & 255;
		if (bbp != 3)
			col[3] = pixels[cmp++] & 255;
		data[i] = ((col[3] << 24) | (col[0] << 16) | (col[1] << 8) | col[2]);
		i++;
	}
	return (data);
}

static int		stock_texture(t_object **obj, int i, SDL_Surface *s, char *str)
{
	char		**split;
	char		*path;

	split = ft_strsplit(str, ' ');
	i = -1;
	while (split[++i])
		if (i == 1 && !ft_strcmp("slice", split[i]))
			(*obj)->texture->slice = true;
	(*obj)->texture->type = TEX;
	path = ft_strjoin("./resources/textures/", split[0]);
	if (!path || !(s = IMG_Load(path)))
	{
		free_tab2(&split, i);
		if (path)
			free(path);
		(*obj)->texture->type = NONE;
		return (-1);
	}
	free(path);
	(*obj)->texture->w = s->w;
	(*obj)->texture->h = s->h;
	(*obj)->texture->data_pixels = \
		convert_color((char*)s->pixels, s->w, s->h, s->format->BytesPerPixel);
	return (1);
}

static void		load_texture(t_object **obj, char *str)
{
	SDL_Surface *s;
	int			i;

	i = 0;
	s = NULL;
	if (!ft_strcmp(str, "checkerboard") && (*obj)->texture->type == NONE)
		(*obj)->texture->type = BOARD;
	else if (!ft_strcmp(str, "spectrum") && (*obj)->texture->type == NONE)
		(*obj)->texture->type = SPECTRUM;
	else if ((*obj)->texture->type == NONE)
	{
		if (-1 == stock_texture(obj, i, s, str))
			return ;
	}
}

static void		get_component_addr(t_object *obj, \
									t_vect3 *stk[12], \
									double *rpa[10])
{
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
}

int				stock_cmp_objects(t_object *obj, int r, char *str)
{
	double		*rpa[10];
	t_vect3		*stk[12];

	get_component_addr(obj, stk, rpa);
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
