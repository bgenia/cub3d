/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:06:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 03:09:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

#include <libft/vector/vector.h>
#include <libft/io/printf.h>

void
	map_print(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->witdth)
		{
			ft_printf("%c", map_get(map, j, i));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
