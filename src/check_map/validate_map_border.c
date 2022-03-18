/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:48:47 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/18 20:53:35 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>
#include <cub3d/check_map.h>

#include <stdbool.h>

bool	validate_map_border(t_map *map, size_t i, size_t j, char c)
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
