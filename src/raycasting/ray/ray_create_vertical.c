/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:39:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:56:48 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/raycasting/ray.h>

#include <libft/tuples.h>

t_ray
	ray_create_vertical(t_double2 origin, t_double2 direction)
{
	t_ray	ray;
	double	direction_tan;

	ray = (t_ray){
		.type = RAY_VERTICAL, .origin = origin, .direction = direction
	};
	direction_tan = direction.y / direction.x;
	if (direction.x == 0)
		direction_tan = 1;
	if (direction.x < 0)
	{
		ray.position.x = floor(origin.x) - RAY_CORRECTION_COEFFICENT;
		ray.offset.x = -1;
	}
	if (direction.x > 0)
	{
		ray.position.x = ceil(origin.x);
		ray.offset.x = 1;
	}
	ray.position.y = (origin.x - ray.position.x)
		* -direction_tan + origin.y;
	ray.offset.y = -ray.offset.x * -direction_tan;
	if (direction.x == 0)
		ray.length = INFINITY;
	return (ray);
}
