/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:05:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:23:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>

#include <libft/vector/vector.h>

char
	map_get(t_map *map, size_t x, size_t y)
{
	char	*row;

	if (y >= map->height)
		return ('\0');
	row = map->vec_value[y];
	if (x >= ft_vector_get_size(row))
		return ('\0');
	return (row[x]);
}
