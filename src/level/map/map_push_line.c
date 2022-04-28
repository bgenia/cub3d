/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_push_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:57:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/map.h>

#include <ft/string/string.h>
#include <ft/vector/vector.h>

void
	map_push_line(t_map *map, char *line)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(line);
	i = 0;
	map_add_line(map);
	while (i < length)
	{
		map_push_char(map, line[i]);
		i++;
	}
}
