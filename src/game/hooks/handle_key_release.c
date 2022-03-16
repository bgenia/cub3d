/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 11:26:35 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <X11/keysym.h>

#include <mlx.h>

int
	handle_key_release(int key, t_game_state *state)
{
	if (key == XK_Escape || key == XK_BackSpace)
		mlx_loop_end(state->display.mlx);
	if (key == XK_w || key == XK_Cyrillic_tse
		|| key == XK_s || key == XK_Cyrillic_yeru)
		state->player.movement_direction.y = 0;
	if (key == XK_d || key == XK_Cyrillic_ve
		|| key == XK_a || key == XK_Cyrillic_ef)
		state->player.movement_direction.x = 0;
	return (0);
}
