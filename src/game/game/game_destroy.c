/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/level/level.h>
#include <cub3d/game/game.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>
#include <cub3d/render/display.h>

#include <ft/utils.h>

#include <mlx.h>

void
	game_destroy(t_game_state *state)
{
	asset_manager_free_assets(&state->asset_manager);
	display_destroy(&state->display);
}
