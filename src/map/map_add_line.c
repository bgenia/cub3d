/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:03:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:23:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map.h>

#include <libft/vector/vector.h>

void
	map_add_line(t_map *map)
{
	*(char **)ft_vector_push_back(&map->vec_value) =
		ft_vector_alloc_empty(sizeof(**map->vec_value));
	map->height++;
}
