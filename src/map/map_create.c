/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:54:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 18:17:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

#include <libft/vector/vector.h>

t_map
	map_create(void)
{
	t_map	map;

	map = (t_map){.width = 0, .height = 0};
	map.vec_value = ft_vector_alloc_empty(sizeof(*map.vec_value));
	return (map);
}
