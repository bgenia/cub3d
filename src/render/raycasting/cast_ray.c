/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:36:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 20:38:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/raycasting.h>

t_ray
	cast_ray(
		t_double2 origin,
		t_double2 direction,
		int iteration_limit,
		t_ray_hit_predicate predicate
	)
{
	t_ray	ray_vertical;
	t_ray	ray_horizontal;

	ray_vertical = ray_create_vertical(origin, direction);
	ray_horizontal = ray_create_horizontal(origin, direction);
	ray_cast(&ray_vertical, iteration_limit, predicate);
	ray_cast(&ray_horizontal, iteration_limit, predicate);
	if (ray_vertical.length < ray_horizontal.length)
		return (ray_vertical);
	return (ray_horizontal);
}
