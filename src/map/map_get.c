/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:05:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 03:06:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

char
	map_get(t_map *map, size_t x, size_t y)
{
	return (map->vec_value[y * map->witdth + x]);
}
