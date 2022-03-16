/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:10:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 05:11:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <cub3d/level/level.h>
#include <cub3d/level/map.h>

void
	level_destroy(t_level *level)
{
	free(level->assets.floor_color);
	free(level->assets.ceiling_color);
	free(level->assets.north_texture_path);
	free(level->assets.south_texture_path);
	free(level->assets.west_texture_path);
	free(level->assets.east_texture_path);
	map_destroy(&level->map);
}
