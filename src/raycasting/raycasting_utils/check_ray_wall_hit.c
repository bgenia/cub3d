/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_wall_hit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 15:10:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/level/map.h>

#include <libft/tuples.h>

bool
	check_ray_wall_hit(t_double2 hit_position, t_map *map)
{
	return (map_get(map, hit_position.x, hit_position.y) == '1');
}
