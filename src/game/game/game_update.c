/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 17:02:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/settings.h>
#include <cub3d/game/game.h>
#include <cub3d/game/loop.h>

void
	game_update(t_game_state *state)
{
	if (state->settings.mouse_rotation)
		update_mouse_movement(state);
	update_player_orientation(state);
	update_player_position(state);
}
