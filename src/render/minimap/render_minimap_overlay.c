/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_overlay.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:00:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:48:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>

void
	render_minimap_overlay(t_game_state *state, t_image *minimap)
{
	int			map_size;

	map_size = state->settings.minimap.size;
	image_fill_circle(minimap, MINIMAP_COLOR_PLAYER,
		ft_int2(map_size / 2, map_size / 2), 5);
	image_draw_circle(minimap, brush_circle(MINIMAP_COLOR_FRAME, 3),
		ft_int2(map_size / 2, map_size / 2), map_size / 2 - 3);
}
