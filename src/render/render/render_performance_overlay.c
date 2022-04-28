/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_performance_overlay.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:48:08 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/settings.h>
#include <cub3d/game/game.h>

#include <ft/string/format.h>

#include <mlx.h>

void
	render_performance_overlay(t_game_state *state)
{
	char	fps_string[16];

	ft_format(fps_string, 16, "fps: %f",
		1 / state->display.renderer.frame_delta);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 15, PERFORMANCE_OVERLAY_COLOR, fps_string);
	ft_format(fps_string, 16, "max: %f",
		1 / state->display.renderer.frame_min);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 27, PERFORMANCE_OVERLAY_COLOR, fps_string);
	ft_format(fps_string, 16, "min: %f",
		1 / state->display.renderer.frame_max);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 39, PERFORMANCE_OVERLAY_COLOR, fps_string);
	ft_format(fps_string, 16, "avg: %f",
		1 / state->display.renderer.frame_avg);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 51, PERFORMANCE_OVERLAY_COLOR, fps_string);
}
