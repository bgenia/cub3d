/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_UTILS_H
# define RAYCASTING_UTILS_H

# include <cub3d/level/map.h>
# include <cub3d/raycasting/ray.h>

# include <ft/tuples.h>

bool
check_ray_wall_hit(t_double2 hit_position, t_map *map);

void
ray_scale(t_ray *ray, double scale);

double
ray_get_view_plane_distance(t_ray *ray, t_double2 view_direction);

#endif
