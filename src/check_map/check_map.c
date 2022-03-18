/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:48:13 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/18 20:54:33 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>
#include <cub3d/check_map.h>

#include <libft/io/printf.h>
#include <libft/string/string.h>

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
			if (!validate_map_char(map_get(map, j, i))
				|| !validate_map_border(map, i, j, map_get(map, j, i)))
				ft_exitf(STDERR_FILENO, EXIT_FAILURE,
					"Error\nInvalid character in map\n");
			if (ft_strchr("NSEW", map_get(map, j, i))
				&& map_get(map, j, i) != '\0')
				count_heroes++;
			j++;
		}
		i++;
	}
	if (count_heroes != 1)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nThere must be one hero\n");
}
