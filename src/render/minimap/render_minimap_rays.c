/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_rays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:31:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/settings.h>
#include <cub3d/game/game.h>
#include <cub3d/graphics/image.h>
#include <cub3d/raycasting/ray.h>
#include <cub3d/raycasting/raycaster.h>
#include <cub3d/raycasting/raycasting_utils.h>
#include <cub3d/vecmath.h>
#include <cub3d/graphics/drawing.h>

#include <ft/tuples.h>
#include <ft/math.h>

#include <ft/io/printf.h>

static void
	_draw_minimap_ray(t_game_state *state, t_ray *ray)
{
	int			map_size;
	t_double2	position;

	map_size = state->settings.minimap.size;
	position = ray->position;
	position.x -= state->player.position.x;
	position.y -= state->player.position.y;
	position = vec_scale(position, state->settings.minimap.scale);
	position.x += state->settings.minimap.size / 2;
	position.y += state->settings.minimap.size / 2;
	image_draw_line(&state->display.minimap, brush_circle(MINIMAP_COLOR_RAY, 0),
		ft_int2(map_size / 2, map_size / 2),
		ft_int2(position.x, position.y));
}

void
	render_minimap_rays(t_game_state *state)
{
	t_raycaster	raycaster;
	int			iteration_limit;
	t_ray		ray;

	raycaster = raycaster_create(
			state->player.position,
			state->player.direction,
			ft_deg2rad(state->settings.fov),
			state->settings.minimap.ray_count
			);
	iteration_limit = state->settings.minimap.size
		/ state->settings.minimap.scale;
	while (!raycaster.done)
	{
		ray = raycaster_cast_next_ray(&raycaster, iteration_limit,
				(t_ray_hit_predicate){(void *)check_ray_wall_hit, &state->map});
		_draw_minimap_ray(state, &ray);
	}
}
