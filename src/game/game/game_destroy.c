/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:27:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/level/level.h>
#include <cub3d/game/game.h>
#include <cub3d/render/window.h>
#include <cub3d/render/renderer.h>

#include <libft/utils.h>

#include <mlx.h>

void
	game_destroy(t_game_state *state)
{
	asset_manager_free_assets(&state->asset_manager);
	game_display_destroy(&state->display);
}
