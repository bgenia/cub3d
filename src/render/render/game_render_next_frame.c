/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 12:50:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/render/render.h>
#include <cub3d/render/minimap.h>
#include <cub3d/render/scene.h>

void
	game_render_next_frame(t_game_state *state)
{
	render_scene(state);
	if (state->settings.minimap.enabled)
		render_minimap(state);
	renderer_render_next_frame(&state->display.renderer);
	if (state->settings.performance_overlay)
		render_performance_overlay(state);
}
