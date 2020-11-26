/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:30:51 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/09 03:17:44 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define W 800
# define H 800
# define PI 3.14159265

enum	e_error {
	FILE_ERROR,
	MALLOC_ERROR,
	EMPTY_FILE,
	READ_FILE,
	CAMERA_ERROR,
	VECTOR_READ,
	SCALAR_READ,
	COLOR_READ,
	SYNTAX_ERROR,
	OBJECT_UNDEFINED,
	OBJECT_PROPERTY,
	GOODBYE
};

enum	e_object_type {
	PLANE,
	SPHERE,
	CYLINDER,
	CONE
};

#endif
