/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:36:36 by nabouzah          #+#    #+#             */
/*   Updated: 2021/02/23 17:08:19 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../includes/rt.h"

// t_ray           obj_intersect(t_object *p, t_hit *hit, t_ray ray, double t)
//  {
//      t_ray       save;

//      while (p)
//      {
//          if (p->type == SPHERE)
//              ft_sphere_intersect(p, &ray, &t);
//          else if (p->type == PLANE)
//              ft_plane_intersect(p, &ray, &t);
//          else if (p->type == CYLINDER)
//              ft_cylinder_intersect(p, &ray, &t);
//          else if (p->type == CONE)
//              ft_cone_intersect(p, &ray, &t);
//          else if (p->type == BOX)
//              box_intersect(p, &ray, &t);
//          else if (p->type == PARALLELOGRAM)
//              ft_parallelogram_intersect(p, &ray, &t);
//          if (hit->t > t)
//          {
//              hit->t = t;
//              hit->object = p;
//              save = ray;
//          }
//          p = p->next;
//      }
//      return (save);
//  }