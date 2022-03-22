/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:48:47 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/22 17:12:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/level/map.h>

bool
	validate_map_border(t_map *map, size_t i, size_t j, char c)
{
	if (c == TILE_WALL || c == TILE_VOID)
		return (true);
	return (map_get(map, j + 1, i) != TILE_VOID
		&& map_get(map, j - 1, i) != TILE_VOID
		&& map_get(map, j, i + 1) != TILE_VOID
		&& map_get(map, j, i - 1) != TILE_VOID);
}
