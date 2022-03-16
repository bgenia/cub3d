/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:54:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 15:22:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>

# include <cub3d/asset_manager.h>
# include <cub3d/map.h>
# include <cub3d/render/renderer.h>
# include <cub3d/parser.h>

# include <libft/tuples.h>

typedef struct s_game_settings
{
	size_t	window_width;
	size_t	window_height;
	double	fov;
	bool	sync;
}	t_game_settings;

typedef struct s_game_display
{
	void			*mlx;
	t_window		window;
	t_renderer		renderer;
}	t_game_display;

t_game_display
game_display_create(t_game_settings settings);
void
game_display_destroy(t_game_display *display);

typedef struct s_game_state
{
	t_game_settings	settings;
	t_game_display	display;
	t_asset_manager	asset_manager;
	t_map			map;
	struct s_player {
		t_double2	position;
		t_double2	direction;
		t_int2		movement_direction;
		int			rotation_direction;
	}				player;
}	t_game_state;

t_game_state
game_create(t_game_settings settings);
void
game_destroy(t_game_state *state);

void
game_setup(t_game_state *state, t_cub_file *cub_file);

void
game_loop(t_game_state *state);

void
game_update(t_game_state *state);

#endif
