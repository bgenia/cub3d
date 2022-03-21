/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_get_view_plane_distance.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:14:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 17:18:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/raycasting/raycasting.h>
#include <cub3d/vecmath.h>

#include <libft/math.h>

double
	ray_get_view_plane_distance(t_ray *ray, t_double2 view_direction)
{
	return (ft_absd(ray->length * vec_dot(ray->direction, view_direction)));
}
