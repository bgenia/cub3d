/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 15:28:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/game/game.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>

#define PLAYER_SPEED 1.75e-5
#define PLAYER_ANGULAR_SPEED M_PI * 5e-5

static void
	_update_player_position(t_game_state *state)
{
	t_double2	straight_movement;
	t_double2	side_movement;
	t_double2	movement;

	straight_movement = state->player.direction;
	straight_movement = vec_scale(straight_movement,
			state->player.movement_direction.y * PLAYER_SPEED);
	side_movement = vec_rotate(state->player.direction, -M_PI / 2);
	side_movement = vec_scale(side_movement,
			state->player.movement_direction.x * PLAYER_SPEED);
	movement = vec_add(straight_movement, side_movement);
	state->player.position = vec_add(state->player.position, movement);
}

static void
	_update_player_orientation(t_game_state *state)
{
	state->player.direction = vec_rotate(
			state->player.direction,
			PLAYER_ANGULAR_SPEED * state->player.rotation_direction
			);
}

void
	game_update(t_game_state *state)
{
	_update_player_orientation(state);
	_update_player_position(state);
}
