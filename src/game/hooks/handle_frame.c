/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 18:50:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/game/render.h>

int
	handle_frame(t_game_state *state)
{
	game_update(state);
	game_render_next_frame(state);
	return (0);
}
