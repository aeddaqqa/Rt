/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:08:19 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/14 18:08:36 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*t_vec   ft_translation(t_vec a, t_vec b)
{
    return (ft_vectoradd(a, b));
}*/

float  deg_to_rad(float angle)
{
    return ((angle * M_PI) / 180);
}

t_vec   x_rotation(t_vec v, float theta)
{
    t_vec   result;

    theta = deg_to_rad(theta);
    result = v;
    result.y = v.y * cos(theta) + v.z * -sin(theta);
    result.z = v.y * sin(theta) + v.z * cos(theta);
    return (result);
}

t_vec   y_rotation(t_vec v, float theta)
{
    t_vec   result;

    theta = deg_to_rad(theta);
    result = v;
    result.x = v.x * cos(theta) + v.z * sin(theta);
    result.z = v.x * -sin(theta) + v.z * cos(theta);
    return (result);
}

t_vec   z_rotation(t_vec v, float theta)
{
    t_vec   result;

    theta = deg_to_rad(theta);
    result = v;
    result.x = v.x * cos(theta) + v.y * -sin(theta);
    result.y = v.x * sin(theta) + v.y * cos(theta);
    return (result);
}