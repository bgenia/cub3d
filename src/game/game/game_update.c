/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 14:28:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/game/game.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>
#include <libft/math.h>

#include <mlx.h>

#include <libft/io/printf.h>

static void
	_update_player_position(t_game_state *state)
{
	t_double2	straight_movement;
	t_double2	side_movement;
	t_double2	movement;

	straight_movement = state->player.direction;
	straight_movement = vec_scale(straight_movement,
			state->player.movement_direction.y * state->settings.movement_speed
			);
	straight_movement = vec_scale(straight_movement,
			state->display.renderer.frame_delta);
	side_movement = vec_rotate(state->player.direction, -M_PI / 2);
	side_movement = vec_scale(side_movement, state->player.movement_direction.x
			* state->settings.movement_speed);
	side_movement = vec_scale(side_movement,
			state->display.renderer.frame_delta);
	movement = vec_add(straight_movement, side_movement);
	movement = vec_scale(movement, state->player.shift_multiplier);
	state->player.position = vec_add(state->player.position, movement);
}

static void
	_update_player_orientation(t_game_state *state)
{
	state->player.direction = vec_rotate(
			state->player.direction,
			state->settings.rotation_speed * state->player.rotation_direction
			* state->display.renderer.frame_delta
			);
	state->player.direction = vec_rotate(
			state->player.direction,
			state->settings.rotation_speed * state->player.mouse_movement
			* state->display.renderer.frame_delta
			);
}

static void
	_update_mouse_movement(t_game_state *state)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(state->display.mlx,
		state->display.window.mlx_window, &x, &y);
	state->player.mouse_movement = ft_clamp(x - state->player.mouse_x, -1, 1);
	state->player.mouse_x = x;
}

void
	game_update(t_game_state *state)
{
	_update_mouse_movement(state);
	ft_printf(">> %d\n", state->player.mouse_movement);
	_update_player_orientation(state);
	_update_player_position(state);
}
