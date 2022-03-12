/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:57:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 03:20:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

#include <libft/vector/vector.h>

void
	map_add_line(t_map *map, char *line)
{
	size_t	i;

	i = 0;
	while (i < map->witdth)
	{
		*(char *)ft_vector_push_back(&map->vec_value) = line[i];
		i++;
	}
}
