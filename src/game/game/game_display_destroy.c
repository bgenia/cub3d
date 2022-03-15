/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:26:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 17:51:51 by bgenia           ###   ########.fr       */
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
	mlx_destroy_display(display->mlx);
	free(display->mlx);
}
