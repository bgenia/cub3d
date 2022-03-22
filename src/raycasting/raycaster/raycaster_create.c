/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:30:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:57:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/raycasting/raycaster.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>

t_raycaster
	raycaster_create(
		t_double2 origin,
		t_double2 direction,
		double fov,
		int ray_count
	)
{
	t_raycaster	result;

	result = (t_raycaster){
		.origin = origin,
		.direction = direction,
		.fov = fov,
		.ray_count = ray_count,
		.ray_index = 0
	};
	result.end_tangent = tan(fov / 2);
	result.current_tangent = -result.end_tangent;
	result.tangent_offset = 2 * result.end_tangent / (ray_count - 1);
	result.ray_direction = vec_rotate(direction, atan(result.current_tangent));
	result.done = result.current_tangent > result.end_tangent;
	return (result);
}
