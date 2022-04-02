/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:48:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/03 02:55:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/game/game.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>

void
	update_player_position(t_game_state *state)
{
	t_double2	straight_movement;
	t_double2	side_movement;
	t_double2	movement;
	t_double2	new_position;

	straight_movement = state->player.direction;
	straight_movement = vec_scale(straight_movement,
			state->player.movement_direction.y
			* state->settings.movement_speed);
	straight_movement = vec_scale(straight_movement,
			state->display.renderer.frame_delta);
	side_movement = vec_rotate(state->player.direction, -M_PI / 2);
	side_movement = vec_scale(side_movement, state->player.movement_direction.x
			* state->settings.movement_speed);
	side_movement = vec_scale(side_movement,
			state->display.renderer.frame_delta);
	movement = vec_add(straight_movement, side_movement);
	movement = vec_scale(movement, state->player.shift_multiplier);
	new_position = vec_add(state->player.position, movement);
	if (map_get(&state->map, new_position.x, new_position.y) != TILE_WALL)
		state->player.position = new_position;
}
