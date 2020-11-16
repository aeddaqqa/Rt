/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 05:10:29 by nabouzah          #+#    #+#             */
/*   Updated: 2020/11/09 05:30:22 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_light	*init_light(t_rt *rt)
{
	t_light	*new;

	if (!(new = (t_light *)malloc(sizeof(t_light))))
		destroy(rt, MALLOC_ERROR);
	new->pos = (t_vector){0.0, 0.0, 0.0};
	new->intensity = 0.0;
	new->color = (t_color){0.0, 0.0, 0.0};
	return (new);
}

static void		check_light_args(t_rt *rt, char ***s)
{
	char	**data;

	data = *s;
	if (data && data[0] && (!data[1] || !data[1][0]))
	{
		ft_putendl("LIGHT");
		ft_putstr("ARGUMENT: ");
		ft_putendl(data[0]);
		ft_putendl("HAS NO VALUE");
		ft_strdel(&data[0]);
		free_double_ptr(s);
		destroy(rt, OBJECT_PROPERTY);
	}
}

void			new_light(t_rt *rt, int fd)
{
	t_light *new;
	t_light *tmp;
	int		comp;
	char	**s;

	comp = 3;
	new = init_light(rt);
	while (comp--)
	{
		if (!(s = value(rt, fd)))
			continue;
		check_light_args(rt, &s);
		is_vect(s[0]) == 'o' ?\
				new->pos = read_vector(&s[1]) : (t_vector){0, 0, 0};
		is_scalar(s[0]) == 'c' ?\
					new->color = read_color(&s[1]) : (t_color){0, 0, 0};
		is_scalar(s[0]) == 'i' ? new->intensity = read_scalar(&s[1]) / 100 : 0;
		ft_strdel(&s[0]);
	}
	free(s);
	tmp = rt->lights;
	rt->lights = new;
	new->next = tmp;
	rt->nbr_lights++;
}
