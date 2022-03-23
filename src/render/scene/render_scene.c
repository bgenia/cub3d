/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:57:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/24 00:53:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/raycasting/ray.h>
#include <cub3d/raycasting/raycaster.h>
#include <cub3d/raycasting/raycasting_utils.h>
#include <cub3d/render/scene.h>

#include <libft/tuples.h>
#include <libft/math.h>

void
	render_scene(t_game_state *state)
{
	t_raycaster	raycaster;
	int			iteration_limit;
	t_ray		ray;

	raycaster = raycaster_create(
			state->player.position,
			state->player.direction,
			ft_deg2rad(state->settings.fov),
			state->display.window.width / state->settings.column_width
			);
	iteration_limit = ft_max(state->map.width, state->map.height);
	while (!raycaster.done)
	{
		ray = raycaster_cast_ray(&raycaster, iteration_limit,
				(t_ray_hit_predicate){(void *)check_ray_wall_hit, &state->map});
		render_column(state, &ray, raycaster.ray_index, raycaster.ray_count);
		raycaster_update_angle(&raycaster);
	}
	clear_depth_data(state);
}
