/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:14:39 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:47:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>
#include <cub3d/render/minimap.h>

void
	render_minimap(t_game_state *state)
{
	render_minimap_walls(state, &state->display.minimap);
	if (state->settings.minimap.ray_count > 0)
		render_minimap_rays(state, &state->display.minimap);
	render_minimap_overlay(state, &state->display.minimap);
	image_put_image(state->display.renderer.next_frame,
		&state->display.minimap, state->settings.minimap.position);
}
