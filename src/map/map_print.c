/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:06:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 22:37:54 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>

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
		while (j < map->width)
		{
			ft_printf("%c", map_get(map, j, i));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
