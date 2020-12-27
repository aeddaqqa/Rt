/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:46:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 14:05:38 by farwila          ###   ########.fr       */
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
	CONE
}				t_type;

#endif
