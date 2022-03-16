/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_push_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:23:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/map.h>

#include <libft/vector/vector.h>
#include <libft/math.h>

void
	map_push_char(t_map *map, char c)
{
	size_t	new_length;

	if (map->height == 0)
		map_add_line(map);
	*(char *)ft_vector_push_back(&map->vec_value[map->height - 1]) = c;
	new_length = ft_vector_get_size(map->vec_value[map->height - 1]);
	map->width = ft_max(map->width, new_length);
}
