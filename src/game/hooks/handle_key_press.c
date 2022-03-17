/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 11:49:18 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

int
	handle_key_press(int key, t_game_state *state)
{
	if (key == 0xd)
		state->player.movement_direction.y = 1;
	if (key == 0x1)
		state->player.movement_direction.y = -1;
	if (key == 0x2)
		state->player.movement_direction.x = -1;
	if (key == 0x0)
		state->player.movement_direction.x = 1;
	if (key == 0x7c)
		state->player.rotation_direction = 1;
	if (key == 0x7b)
		state->player.rotation_direction = -1;
	if (key == 0x101)
		state->player.shift_multiplier = state->settings.shift_multiplier;
	return (0);
}
