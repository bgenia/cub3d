/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:55:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 18:01:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>
#include <cub3d/parser.h>

void
	game_setup(t_game_state *state, t_cub_file *cub_file)
{
	register_hooks(state->display.mlx, state);
	state->map = cub_file->map;
	state->asset_manager = asset_manager_create(state->display.mlx);
	asset_manager_load_assets(&state->asset_manager, cub_file->assets);
}
