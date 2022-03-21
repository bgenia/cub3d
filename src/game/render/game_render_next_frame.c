/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 14:55:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/game/render.h>
#include <cub3d/vecmath.h>
#include <cub3d/level/map.h>
#include <cub3d/render/raycasting.h>
#include <cub3d/render/color.h>
#include <cub3d/render/graphics.h>

#include <libft/io/printf.h>
#include <libft/tuples.h>
#include <libft/math.h>

void
	game_render_next_frame(t_game_state *state)
{
	game_render_level(state);
	game_render_minimap(state);
	renderer_render_next_frame(&state->display.renderer);
}
