/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_update_angle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:44:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:56:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/raycasting/raycaster.h>
#include <cub3d/vecmath.h>

void
	raycaster_update_angle(t_raycaster *raycaster)
{
	raycaster->current_tangent += raycaster->tangent_offset;
	raycaster->ray_direction = vec_rotate(
			raycaster->direction,
			atan(raycaster->current_tangent)
			);
	raycaster->ray_index++;
	raycaster->done = raycaster->current_tangent > raycaster->end_tangent;
}
