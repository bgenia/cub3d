/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:05:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/map.h>

#include <ft/vector/vector.h>

char
	map_get(t_map *map, size_t x, size_t y)
{
	char	*row;

	if (y >= ft_vector_get_size(map->vec_value))
		return (TILE_VOID);
	row = map->vec_value[y];
	if (x >= ft_vector_get_size(row))
		return (TILE_VOID);
	return (row[x]);
}
