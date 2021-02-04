/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:14:45 by nabouzah          #+#    #+#             */
/*   Updated: 2021/01/30 19:14:47 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color			specular(t_light *l, t_ray *ray, t_obj *object)
{
	t_color			color;
	t_vector		h;
	unsigned int	alpha;
	double			dot;

	color = (t_color){0.0, 0.0, 0.0};
	alpha = 300;
	h = normalize(vect_sub(l->dir, ray->direction));
	if ((dot = dot(object->normal, h)) <= 0)
		return (color);
	dot = powf(dot, alpha);
	color = fraction(l->color, dot * l->intensity);
	return (color);
}
