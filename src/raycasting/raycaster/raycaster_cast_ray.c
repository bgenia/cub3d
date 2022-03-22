/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_cast_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:49:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/raycasting/ray.h>
#include <cub3d/raycasting/raycaster.h>

t_ray
	raycaster_cast_ray(
		t_raycaster *raycaster,
		int iteration_limit,
		t_ray_hit_predicate predicate
	)
{
	return (cast_ray(
			raycaster->origin,
			raycaster->ray_direction,
			iteration_limit,
			predicate
		));
}
