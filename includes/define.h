/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:46:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/21 22:14:34 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**				Error-gen
*/

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
