/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:33 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/30 19:17:53 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color			ambient(t_object *obj, t_rt rt)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, rt->ambient);
	color = vect_prod(color, obj->color);
	return (color);
}
