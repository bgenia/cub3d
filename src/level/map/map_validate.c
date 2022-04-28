/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:48:13 by drohanne          #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/level/map.h>

#include <ft/string/string.h>
#include <ft/utils.h>

void
	map_validate(t_map *map)
{
	size_t	i;
	size_t	j;
	int		count_heroes;

	count_heroes = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!validate_map_char(map_get(map, j, i)))
				ft_exitf(STDERR_FILENO, EXIT_FAILURE,
					"Error\nInvalid character in map\n");
			if (!validate_map_border(map, i, j, map_get(map, j, i)))
				ft_exitf(STDERR_FILENO, EXIT_FAILURE,
					"Error\nUnclosed map\n");
			if (ft_strchr(PLAYER_TILES, map_get(map, j, i)))
				count_heroes++;
			j++;
		}
		i++;
	}
	if (count_heroes != 1)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nThere must be one hero\n");
}
