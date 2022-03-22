/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_cast_next_ray.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:47:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:58:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/raycasting/ray.h>
#include <cub3d/raycasting/raycaster.h>

t_ray
	raycaster_cast_next_ray(
		t_raycaster *raycaster,
		int iteration_limit,
		t_ray_hit_predicate predicate
	)
{
	t_ray	ray;

	ray = raycaster_cast_ray(raycaster, iteration_limit, predicate);
	raycaster_update_angle(raycaster);
	return (ray);
}
