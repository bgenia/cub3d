/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:45:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/render/render.h>
#include <cub3d/vecmath.h>
#include <cub3d/level/map.h>
#include <cub3d/raycasting/raycasting.h>
#include <cub3d/graphics/color.h>
#include <cub3d/graphics/drawing.h>
#include <cub3d/render/minimap.h>
#include <cub3d/render/scene.h>

#include <libft/tuples.h>
#include <libft/math.h>

void
	game_render_next_frame(t_game_state *state)
{
	render_scene(state);
	render_minimap(state);
	renderer_render_next_frame(&state->display.renderer);
}
