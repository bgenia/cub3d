/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mouse_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:50:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 14:53:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <libft/tuples.h>
#include <libft/math.h>

#include <mlx.h>

void
	update_mouse_movement(t_game_state *state)
{
	t_int2	position;

	mlx_mouse_get_pos(state->display.mlx,
		state->display.window.mlx_window, &position.x, &position.y);
	state->player.mouse_movement = \
			ft_clamp(position.x - state->player.mouse_x, -100, 100);
	state->player.mouse_movement = ft_xmapd(state->player.mouse_movement,
			ft_double2(-100, 100), ft_double2(-10, 10));
	state->player.mouse_x = position.x;
}
