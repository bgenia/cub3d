/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 17:30:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <cub3d/game/game.h>

int
handle_exit(t_game_state *state);

int
handle_key_press(int key, t_game_state *state);

int
handle_key_release(int key, t_game_state *state);

int
handle_frame(t_game_state *state);

void
register_hooks(t_game_state *state);

#endif
