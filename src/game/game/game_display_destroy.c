/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 11:40:35 by bgenia           ###   ########.fr       */
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
	game_display_destroy(t_game_display *display)
{
	renderer_destroy(&display->renderer);
	window_destroy(&display->window);
	// mlx_destroy_display(display->mlx);
	free(display->mlx);
}
