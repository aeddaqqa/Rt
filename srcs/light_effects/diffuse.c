/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:02 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/30 19:18:02 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color			diffuse(t_light *light, double n_l, t_object *object)
{
	t_color		color;

	color =\
		multip_color(fraction(light->color, light->intensity), object->color);
	color = fraction(color, n_l);
	return (color);
}
