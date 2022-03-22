/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:12:29 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:57:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/raycasting/ray.h>

void
	ray_scale(t_ray *ray, double scale)
{
	ray->origin.x *= scale;
	ray->origin.y *= scale;
	ray->position.x *= scale;
	ray->position.y *= scale;
}
