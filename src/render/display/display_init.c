/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 14:55:18 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/game/game.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>
#include <cub3d/graphics/drawing.h>

#include <libft/utils.h>
#include <libft/tuples.h>
#include <libft/vector/vector.h>

#include <mlx.h>

static void
	_init_minimap(t_display *display, t_game_settings settings)
{
	int		map_size;

	map_size = settings.minimap.size;
	display->minimap = image_create(display->mlx, map_size, map_size);
	display->minimap_mask = image_create(display->mlx,
			display->minimap.width, display->minimap.height);
	image_fill_circle(&display->minimap_mask, 0x33ffffff,
		ft_int2(map_size / 2, map_size / 2), map_size / 2 - 1);
	image_use_mask(&display->minimap, &display->minimap_mask);
}

static void
	_init_depth_buffer(t_display *display)
{
	display->vec_depth = ft_vector_alloc_with_capacity(
			sizeof(double),
			display->window.width
			);
}

void
	display_init(t_display *display, t_game_settings settings)
{
	display->mlx = mlx_init();
	mlx_do_key_autorepeatoff(display->mlx);
	if (!display->mlx)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE,
			"Error\nUnable to initialize mlx\n");
	_init_depth_buffer(display);
	display->window = window_create(display->mlx, settings.window_width,
			settings.window_height, "bgenia/drohanne:cub3d");
	renderer_init(&display->renderer, &display->window, settings.sync);
	_init_minimap(display, settings);
}
