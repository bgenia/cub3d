/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:39:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 21:32:44 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/render/raycasting.h>

#include <libft/tuples.h>

t_ray
	ray_create_vertical(t_double2 origin, t_double2 direction)
{
	t_ray	ray;
	double	direction_ctg;

	ray = (t_ray){
		.type = RAY_VERTICAL,
		.origin = origin,
		.direction = direction
	};
	direction_ctg = direction.x / direction.y;
	if (direction.y < 0)
	{
		ray.position.y = floor(origin.y) - RAY_CORRECTION_COEFFICENT;
		ray.offset.y = -1;
	}
	if (direction.y > 0)
	{
		ray.position.y = ceil(origin.y);
		ray.offset.y = 1;
	}
	ray.position.x = (origin.y - ray.position.y)
		* -direction_ctg + origin.x;
	ray.offset.x = -ray.offset.y * -direction_ctg;
	if (direction.y == 0)
		ray.length = INFINITY;
	return (ray);
}
