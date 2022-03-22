/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:46:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 14:48:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include <cub3d/game/game.h>

void
update_player_position(t_game_state *state);

void
update_player_orientation(t_game_state *state);

void
update_mouse_movement(t_game_state *state);

#endif
