/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 05:24:37 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 13:17:56 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		destroy(t_error type)
{
	if (type == FLAG_SAVE)
		ft_putendl("Flag Save Incorrect");
	else if (type == OPEN_FILE)
		ft_putendl("Open File Frror");
	else if (type == EMPTY_FILE)
		ft_putendl("Empty File");
	else if (type == MALLOC_ERROR)
		ft_putendl("Memory Allocation Error");
	else if (type == SCENE_NOT_FOUND)
		ft_putendl("Scene Not Found");
	else if (type == SYNTAX_ERROR)
		ft_putendl("Syntax Error");
}
