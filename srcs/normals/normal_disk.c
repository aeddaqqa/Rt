/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:50:17 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/07 18:06:25 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3		normal_disk(t_object *disk, t_ray *ray)
{
	t_vect3	n;

	(void)ray;
	n = disk->orientation;
	return (n);
}
