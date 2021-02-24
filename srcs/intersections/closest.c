/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:39:00 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/24 14:18:35 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_min_ray(double t1, double t2, double *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (*t);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (*t);
	}
	else
		return (-1);
}

// double		ft_min_ray(double t1, double t2, double *t)
// {
// 	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
// 	{
// 		*t = t1;
// 		return (*t);
// 	}
// 	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
// 	{
// 		*t = t2;
// 		return (*t);
// 	}
// 	else
// 		return (-1);
// }