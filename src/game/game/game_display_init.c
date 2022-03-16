/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 17:58:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/game/game.h>
#include <cub3d/render/window.h>
#include <cub3d/render/renderer.h>

#include <libft/utils.h>

#include <mlx.h>

void
	game_display_init(t_game_display *display, t_game_settings settings)
{
	display->mlx = mlx_init();
	mlx_do_key_autorepeatoff(display->mlx);
	if (!display->mlx)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE,
			"cub3d: fatal: unable to initialize mlx\n");
	display->window = window_create(display->mlx, settings.window_width,
			settings.window_height, "bgenia/drohanne:cub3d");
	renderer_init(&display->renderer, &display->window, settings.sync);
}
