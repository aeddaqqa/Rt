/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:33 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/24 09:31:59 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

st_color			ambient(t_object *obj)
{
	t_color		color;

	color = v_c_prod((t_color){1.0, 1.0, 1.0}, 0.2);
	color = vect_prod(color, obj->color);
	return (color);
}