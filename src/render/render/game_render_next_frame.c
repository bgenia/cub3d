/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 22:41:11 by bgenia           ###   ########.fr       */
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
	char	fps_string[32];

	ft_format(fps_string, 16, "fps: %f",
		1 / state->display.renderer.frame_delta);
	mlx_string_put(state->display.mlx, state->display.window.mlx_window,
		10, 10, 0x00ff00, fps_string);
}

void
	game_render_next_frame(t_game_state *state)
{
	render_scene(state);
	render_minimap(state);
	renderer_render_next_frame(&state->display.renderer);
	_render_fps_counter(state);
}
