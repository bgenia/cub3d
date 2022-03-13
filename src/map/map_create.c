/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:54:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:23:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <cub3d/map.h>

#include <libft/vector/vector.h>

t_map
	map_create(void)
{
	t_map	map;

	map = (t_map){.width = 0, .height = 0};
	map.vec_value = ft_vector_alloc_empty(sizeof(*map.vec_value));
	return (map);
}
