/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:11:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 16:16:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>

#include <mlx.h>

#include <X11/Xlib.h>

void
	register_hooks(void *mlx, t_game_state *game_state)
{
	mlx_hook(mlx, DestroyNotify, None, (void *)handle_exit, game_state);
	mlx_hook(mlx, KeyPress, KeyPressMask, (void *)handle_key_press, game_state);
	mlx_hook(mlx, KeyRelease, KeyReleaseMask,
		(void *)handle_key_release, game_state);
	mlx_loop_hook(mlx, (void *)handle_frame, game_state);
}
