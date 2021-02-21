/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:46:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/21 18:02:43 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**				Error-gen
*/

#define W 800
#define H 800

typedef enum	e_error
{
	FLAG_SAVE,
	OPEN_FILE,
	EMPTY_FILE,
	MALLOC_ERROR,
	SCENE_NOT_FOUND,
	SYNTAX_ERROR
}				t_error;

typedef	enum	e_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	CAMERA,
	LIGHT,
	ELLIPSOID,
	PARABOLOID,
	TRIANGLE,
	BOX,
	PARALLELOGRAM,
	TORUS,
	AMBIENT
}				t_type;

#define COLOR_1 0x192a56
#define COLOR_2 0xfbc531
#define COLOR_3 0xf5f6fa
#define COLOR_4 0x2f3640
#define FONT_P                 \
	{                          \
		0xea, 0xb5, 0x43, 0xff \
	}
#define FONT_S                 \
	{                          \
		0xF8, 0xEF, 0xBA, 0xff \
	}

#endif
