/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 18:10:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <X11/keysym.h>

int
	handle_key_press(int key, t_game_state *state)
{
	if (key == XK_w || key == XK_Cyrillic_tse)
		state->player.movement_direction.y = 1;
	if (key == XK_s || key == XK_Cyrillic_yeru)
		state->player.movement_direction.y = -1;
	if (key == XK_d || key == XK_Cyrillic_ve)
		state->player.movement_direction.x = -1;
	if (key == XK_a || key == XK_Cyrillic_ef)
		state->player.movement_direction.x = 1;
	if (key == XK_Right)
		state->player.rotation_direction = 1;
	if (key == XK_Left)
		state->player.rotation_direction = -1;
	if (key == XK_Shift_L)
		state->player.shift_multiplier = state->settings.shift_multiplier;
	return (0);
}
