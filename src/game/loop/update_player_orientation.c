/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_orientation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 14:50:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/vecmath.h>

void
	update_player_orientation(t_game_state *state)
{
	state->player.direction = vec_rotate(state->player.direction,
			state->settings.rotation_speed * state->player.rotation_direction
			* state->display.renderer.frame_delta);
	state->player.direction = vec_rotate(state->player.direction,
			state->settings.rotation_speed
			* state->player.mouse_movement
			* state->display.renderer.frame_delta);
}
