/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:39:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 19:14:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include <cub3d/raycasting/raycasting.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>

void
	ray_cast(t_ray *ray, int iteration_limit, t_ray_hit_predicate predicate)
{
	int		i;

	if (!isfinite(ray->length))
		return ;
	i = 0;
	while (iteration_limit < 0 || i < iteration_limit)
	{
		if (predicate.predicate(ray->position, predicate.arg))
		{
			ray->hit = false;
			break ;
		}
		ray->position = vec_add(ray->position, ray->offset);
		i++;
	}
	ray->length = vec_distance(ray->origin, ray->position);
}
