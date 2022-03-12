/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:54:28 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 03:14:06 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

#include <libft/vector/vector.h>

t_map
	map_create(size_t width, size_t height)
{
	return ((t_map){
		.witdth = width,
		.height = height,
		.vec_value = ft_vector_alloc_with_capacity(sizeof(char), width * height)
	});
}
