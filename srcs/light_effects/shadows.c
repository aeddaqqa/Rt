/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/24 09:33:24 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	double		t;
	double		distance;
	t_ray		shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		if (obj != object\
				&& (t = rt->intersection[obj->type](obj, &shadow)) > 0.0)
		{
			shadow.hit_point = v_c_prod(shadow.direction, t);
			distance = sqrtf(dot(shadow.hit_point, shadow.hit_point));
			if (distance < light->d)
				return (0);
		}
		obj = obj->next;
	}
	return (1);
}