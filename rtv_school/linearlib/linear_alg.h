/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_alg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:08:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/23 10:04:34 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALG_H
# define LINEAR_ALG_H

# include <math.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

float			ft_magnitude(t_vec v);
t_vec			ft_normalize(t_vec v);
t_vec			ft_negative(t_vec v);
float			ft_dotproduct(t_vec a, t_vec b);
t_vec			ft_crossproduct(t_vec a, t_vec b);
t_vec			ft_vectoradd(t_vec a, t_vec b);
t_vec			ft_vectorsub(t_vec a, t_vec b);
t_vec			ft_vectormulti(t_vec c, float scalar);

#endif
