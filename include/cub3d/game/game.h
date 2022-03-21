/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:54:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:50:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>

# include <cub3d/game/settings.h>
# include <cub3d/level/assets.h>
# include <cub3d/level/map.h>
# include <cub3d/level/level.h>
# include <cub3d/render/display.h>
# include <cub3d/render/display.h>

# include <libft/tuples.h>

typedef struct s_game_state
{
	t_game_settings	settings;
	t_display		display;
	t_asset_manager	asset_manager;
	t_map			map;
	struct s_player {
		t_double2	position;
		t_double2	direction;
		t_int2		movement_direction;
		int			rotation_direction;
		double		shift_multiplier;
	}				player;
}	t_game_state;

void
game_init(t_game_state *state, t_game_settings settings);
void
game_destroy(t_game_state *state);

void
game_setup(t_game_state *state, t_level *level);

void
game_loop(t_game_state *state);

void
game_update(t_game_state *state);

#endif
