/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:10:58 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/28 12:47:25 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int    ft_parse_camera(t_mx *v, char **token)
{
    t_vec       pos;
    t_vec       at;
    float       vfov;
    int         len;
    
    len = ft_strsplit_len(token);
    pos = (t_vec){0,0,0};
    at = (t_vec){0,0,0};
    vfov = 0.0f;
    if (len == 4 && token)
    {
        if (ft_check_vectors(token[1]) && ft_check_vectors(token[2])
        && ft_check_camera_fov(token[3]))
        {
            if (token[1])
                pos = string_to_vect(token[1]);
            if (token[2])
                at = string_to_vect(token[2]);
            if (token[3])
                vfov = ft_atof(token[3]);
            v->cam = ft_camera_create(pos, at, (t_vec){0, 1, 0}, vfov);
        }
        else
            return (0);
    }
    else
        return (0);
    return (1);
}