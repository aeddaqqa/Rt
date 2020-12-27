/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:42:30 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/27 13:18:12 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_rt		*init_rt(bool save)
{
	t_rt	*new;

	if (!(new = malloc(sizeof(t_rt))))
		return (NULL);
	new->save = save;
	new->cameras = NULL;
	new->lights = NULL;
	new->objects = NULL;
	return (new);
}
