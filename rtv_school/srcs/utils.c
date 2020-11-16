/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:13:28 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/14 18:13:30 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float clamp(float value, float min, float max)
{
    if (value < min)
    {
        value = min;
    }
    else if (value > max)
    {
        value = max;
    }
    return (value);
}

t_vec   clamp_vect(t_vec v)
{
    v.x = clamp(v.x * 255, 0.0f, 255.0f);
    v.y = clamp(v.y * 255, 0.0f, 255.0f);
    v.z = clamp(v.z * 255, 0.0f, 255.0f);
    return (v);
}

int rgb_to_int(t_vec v)
{
    int red;
    int green;
    int blue;
    int rgb;

    red = (int)v.x;
    green = (int)v.y;
    blue = (int)v.z;

    rgb = red;
    rgb = (rgb << 8) + green;
    rgb = (rgb << 8) + blue;
    return (rgb);
}