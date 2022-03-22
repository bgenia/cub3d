/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 08:20:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/render/render.h>
#include <cub3d/render/minimap.h>
#include <cub3d/render/scene.h>

#include <libft/tuples.h>
#include <libft/math.h>
#include <libft/string/format.h>

#include <mlx.h>

static void
	_render_fps_counter(t_game_state *state)
{
	char	fps_string[16];

	ft_format(fps_string, 16, "fps: %f",
		1 / state->display.renderer.frame_delta);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 15, 0x00ff00, fps_string);
	ft_format(fps_string, 16, "max: %f",
		1 / state->display.renderer.frame_min);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 27, 0x00ff00, fps_string);
	ft_format(fps_string, 16, "min: %f",
		1 / state->display.renderer.frame_max);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 39, 0x00ff00, fps_string);
	ft_format(fps_string, 16, "avg: %f",
		1 / state->display.renderer.frame_avg);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 51, 0x00ff00, fps_string);
}

void
	game_render_next_frame(t_game_state *state)
{
	render_scene(state);
	if (state->settings.minimap.enabled)
		render_minimap(state);
	renderer_render_next_frame(&state->display.renderer);
	if (state->settings.fps_counter)
		_render_fps_counter(state);
}
