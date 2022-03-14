/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create_horizontal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:39:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 20:33:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/render/raycasting.h>

#include <libft/tuples.h>

t_ray
	ray_create_horizontal(t_double2 origin, t_double2 direction)
{
	t_ray	ray;
	double	direction_tan;

	ray = (t_ray){
		.type = RAY_HORIZONTAL,
		.origin = origin,
		.direction = direction
	};
	direction_tan = direction.y / direction.x;
	if (direction.x < 0)
	{
		ray.position.x = origin.x - RAY_CORRECTION_COEFFICENT;
		ray.offset.x = -1;
	}
	if (direction.x > 0)
	{
		ray.position.x = origin.x + 1;
		ray.offset.x = 1;
	}
	ray.position.y = (origin.x - ray.position.x)
		* -direction_tan + origin.y;
	ray.offset.y = -ray.offset.x * -direction_tan;
	if (direction.x == 0)
		ray.length = INFINITY;
	return (ray);
}
