/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:22:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <stdbool.h>

# include <cub3d/raycasting/ray.h>

# include <ft/tuples.h>

typedef struct s_raycaster
{
	t_double2	origin;
	t_double2	direction;
	double		fov;
	int			ray_count;
	int			ray_index;
	double		current_tangent;
	double		end_tangent;
	double		tangent_offset;
	t_double2	ray_direction;
	bool		done;
}	t_raycaster;

t_raycaster
raycaster_create(
	t_double2 origin,
	t_double2 direction,
	double fov,
	int ray_count
	);

t_ray
raycaster_cast_ray(
	t_raycaster *raycaster,
	int iteration_limit,
	t_ray_hit_predicate predicate
	);

void
raycaster_update_angle(t_raycaster *raycaster);

t_ray
raycaster_cast_next_ray(
	t_raycaster *raycaster,
	int iteration_limit,
	t_ray_hit_predicate predicate
	);

#endif
