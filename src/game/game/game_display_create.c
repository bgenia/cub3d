/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 17:45:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/game/game.h>
#include <cub3d/render/window.h>
#include <cub3d/render/renderer.h>

#include <libft/utils.h>

#include <mlx.h>

t_game_display
	game_display_create(t_game_settings settings)
{
	t_game_display	display;

	display.mlx = mlx_init();
	if (!display.mlx)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE,
			"cub3d: fatal: unable to initialize mlx\n");
	display.window = window_create(display.mlx, settings.window_width,
			settings.window_height, "bgenia/drohanne:cub3d");
	display.renderer = renderer_create(&display.window, settings.sync);
	return (display);
}
