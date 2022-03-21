/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:51:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/game/game.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>
#include <cub3d/render/display.h>

#include <libft/utils.h>

#include <mlx.h>

void
	game_init(t_game_state *state, t_game_settings settings)
{
	*state = (t_game_state){.settings = settings};
	state->player = (typeof(state->player)){.shift_multiplier = 1};
	display_init(&state->display, settings);
}
