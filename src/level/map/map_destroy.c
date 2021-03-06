/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:57:08 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/map.h>

#include <ft/vector/vector.h>

void
	map_destroy(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(map->vec_value))
	{
		ft_vector_free(map->vec_value[i]);
		i++;
	}
	ft_vector_free(map->vec_value);
}
