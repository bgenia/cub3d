/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:57:26 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 18:11:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/level/level.h>
#include <cub3d/level/map.h>
#include <cub3d/render/renderer.h>
#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>
#include <cub3d/game/render.h>

#include <libft/tuples.h>
#include <libft/utils.h>

#include <mlx.h>

static t_game_settings
	_get_default_settings(void)
{
	return ((t_game_settings){
		.window_width = 960,
		.window_height = 720,
		.fov = 60,
		.column_width = 1,
		.movement_speed = 3e-2,
		.rotation_speed = 3e-2,
		.shift_multiplier = 3,
		.sync = true
	});
}

int
	main(int argc, char **argv)
{
	t_level			level;
	t_game_state	game_state;

	if (argc < 2)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "cub3d: missing .cub file\n");
	if (argc > 2)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "cub3d: too many arguments\n");
	level = level_load_from_file(argv[1]);
	game_init(&game_state, _get_default_settings());
	game_setup(&game_state, &level);
	game_loop(&game_state);
	game_destroy(&game_state);
	level_destroy(&level);
}
