/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:48:13 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/16 23:40:50 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>
#include <cub3d/parser.h>
#include <cub3d/asset_manager.h>
#include <cub3d/parser.h>
#include <cub3d/check_map.h>

#include <libft/utils.h>
#include <libft/io/printf.h>
#include <libft/string/string.h>

#include <stdio.h>

static bool	validate_map_border(t_map *map, size_t i, size_t j, char c)
{
	size_t	save_i;
	size_t	save_j;

	if (c == '\0')
		return (true);
	if (ft_strchr("0NSEW", c))
	{
		if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			return (false);
		save_i = i;
		while (i >= 0)
		{
			if (map_get(map, j, i) == '1')
			{
				i = save_i;
				while (i < map->height)
				{
					if (map_get(map, j, i) == '1')
					{
						save_j = j;
						while (j >= 0)
						{
							if (map_get(map, j, save_i) == '1')
							{
								j = save_j;
								while (j < map->width)
								{
									if (map_get(map, j, save_i) == '1')
										return (true);
									j++;
								}
								return (false);
							}
							j--;
						}
					}
					i++;
				}
			}
			i--;
		}
	}
	return (true);
}

void	check_map(t_map *map)
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
			if (!validate_map_char(map_get(map, j, i)) || !validate_map_border(map, i, j, map_get(map, j, i)))
				ft_exitf(STDERR_FILENO, EXIT_FAILURE,
					"Error\nInvalid character in map\n");
			if (ft_strchr("NSEW", map_get(map, j, i)) && map_get(map, j, i) != '\0')
				count_heroes++;
			j++;
		}
		i++;
	}
	if (count_heroes != 1)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nThere must be one hero\n");
}
