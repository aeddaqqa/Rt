/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:59:24 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/05 18:36:26 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_FUNCTION_H
# define CAM_FUNCTION_H

t_ray			*ray_init(t_rt *rt, double x, double y, t_rr r);
void			new_camera(t_rt *rt);
#endif
