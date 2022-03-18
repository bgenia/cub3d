/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:48:13 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/18 20:46:29 by drohanne         ###   ########.fr       */
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
/*
static bool	cycle_end(t_cycle temp)
{
	while (temp.j < temp.map->width)
	{
		if (map_get(temp.map, temp.j, temp.save_i) == ' '
			|| map_get(temp.map, temp.j, temp.i) == '\0')
			return (false);
		if (map_get(temp.map, temp.j, temp.save_i) == '1')
			return (true);
		temp.j++;
	}
	return (false);
}

static bool	pre_cycle_end(t_cycle temp)
{
	while (temp.j >= 0 && temp.cycle == 2)
	{
		if (map_get(temp.map, temp.j, temp.save_i) == ' ' || map_get(temp.map, temp.j, temp.i) == '\0')
			return (false);
		if (map_get(temp.map, temp.j, temp.save_i) == '1')
		{
			temp.j = temp.save_j;
			return (cycle_end(temp));
		}
		temp.j--;
	}
	return (false);
}

static bool	validate_map_border(t_map *map, size_t i, size_t j, char c)
{
	t_cycle	temp;

	if (c == '\0' || c == '1' || c == ' ')
		return (true);
	temp.cycle = 0;
	temp.map = map;
	temp.j = j;
	temp.i = i;
	if (ft_strchr("0NSEW", c))
	{
		if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			return (false);
		temp.save_i = i;
		while (temp.i >= 0 && temp.cycle == 0)
		{
			if (map_get(temp.map, temp.j, temp.i) == ' ' || map_get(temp.map, temp.j, temp.i) == '\0')
				return (false);
			if (map_get(temp.map, temp.j, temp.i) == '1')
			{
				temp.cycle++;
				temp.i = temp.save_i;
				while (temp.i < temp.map->height && temp.cycle == 1)
				{
					if (map_get(temp.map, temp.j, temp.i) == ' ' || map_get(temp.map, temp.j, temp.i) == '\0')
						return (false);
					if (map_get(temp.map, temp.j, temp.i) == '1')
					{
						temp.cycle++;
						temp.save_j = temp.j;
						return (pre_cycle_end(temp));
					}
					temp.i++;
				}
			}
			temp.i--;
		}
	}
	return (false);
}
*/

static bool	validate_map_border(t_map *map, size_t i, size_t j, char c)
{
	if (c != '1' && c != ' ' && c != '\0')
	{
		if (ft_strchr("01NSEW", map_get(map, j + 1, i))
			&& map_get(map, j + 1, i) != '\0'
			&& ft_strchr("01NSEW", map_get(map, j - 1, i))
			&& map_get(map, j - 1, i) != '\0'
			&& ft_strchr("01NSEW", map_get(map, j, i + 1))
			&& map_get(map, j, i + 1) != '\0'
			&& ft_strchr("01NSEW", map_get(map, j, i - 1))
			&& map_get(map, j, i - 1) != '\0')
			return (true);
		else
			return (false);
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
