/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:57:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 18:44:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/raycasting.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>

t_ray
	ray_cast_to(
		t_double2 position,
		t_double2 target,
		t_ray_hit_predicate predicate
	)
{
	return (ray_cast(
			position,
			vec_normalize(vec_direction_to(position, target)),
			vec_distance(position, target),
			predicate
		));
}
