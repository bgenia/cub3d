/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_destroy.c                             :+:      :+:    :+:   */
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

#include <libft/utils.h>

#include <mlx.h>

void
	display_destroy(t_display *display)
{
	renderer_destroy(&display->renderer);
	image_destroy(&display->minimap);
	image_destroy(&display->minimap_mask);
	window_destroy(&display->window);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
	free(display->depth_buffer);
	free(display->depth_indices);
}
