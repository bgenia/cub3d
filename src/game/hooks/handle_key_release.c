/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 11:49:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>

#include <mlx.h>

int
	handle_key_release(int key, t_game_state *state)
{
	if (key == 0x35 || key == 0x33)
		handle_exit(state);
	if (key == 0xd || key == 0x1)
		state->player.movement_direction.y = 0;
	if (key == 0x0 || key == 0x2)
		state->player.movement_direction.x = 0;
	if (key == 0x7c || key == 0x7b)
		state->player.rotation_direction = 0;
	if (key == 0x101)
		state->player.shift_multiplier = 1;
	return (0);
}
