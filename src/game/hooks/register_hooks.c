/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:11:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 10:18:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>

#include <mlx.h>

#include <X11/Xlib.h>

void
	register_hooks(t_game_state *game_state)
{
	mlx_hook(game_state->display.window.mlx_window, DestroyNotify, None,
		(void *)handle_exit, game_state);
	mlx_hook(game_state->display.window.mlx_window, KeyPress, KeyPressMask,
		(void *)handle_key_press, game_state);
	mlx_hook(game_state->display.window.mlx_window, KeyRelease, KeyReleaseMask,
		(void *)handle_key_release, game_state);
	mlx_loop_hook(game_state->display.mlx,
		(void *)handle_frame, game_state);
}
