/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:59:24 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/10 19:16:19 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_FUNCTION_H
# define CAM_FUNCTION_H
t_ray	*ray_init(t_rt *rt, double x, double y);
void	cam_cord_system(t_cam *cam);
#endif