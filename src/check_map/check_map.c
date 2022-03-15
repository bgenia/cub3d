/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:48:13 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/15 22:42:56 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>
#include <cub3d/parser.h>
#include <cub3d/asset_manager.h>
#include <cub3d/parser.h>
#include <cub3d/check_map.h>
#include <stdio.h>
#include <stdlib.h>

void	check_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!validate_map_char(map_get(map, j, i)))
				exit(1);
			j++;
		}
		printf("\n");
		i++;
	}
}
