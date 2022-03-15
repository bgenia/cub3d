/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 16:16:31 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <cub3d/game/game.h>

int
handle_exit(t_game_state *game_state);

int
handle_key_press(int key, t_game_state *game_state);

int
handle_key_release(int key, t_game_state *game_state);

int
handle_frame(t_game_state *game_state);

void
register_hooks(void *mlx, t_game_state *game_state);

#endif