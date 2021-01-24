/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:42:30 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/24 11:45:45 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_rt		*init_rt(bool save)
{
	t_rt	*new;

	if (!(new = malloc(sizeof(t_rt))))
		return (NULL);
	new->save = save;
	new->cameras = NULL;
	new->lights = NULL;
	new->objects = NULL;
	new->ambient = 0;
	new->ambient_exist = false;
	return (new);
}
