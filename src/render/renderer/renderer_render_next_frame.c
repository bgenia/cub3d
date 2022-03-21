/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_render_next_frame.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 13:28:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>

#include <mlx.h>

void
	renderer_render_next_frame(t_renderer *renderer)
{
	t_image	*temp_frame;

	window_draw_image(renderer->window, renderer->next_frame);
	temp_frame = renderer->current_frame;
	renderer->current_frame = renderer->next_frame;
	renderer->next_frame = temp_frame;
	if (renderer->sync)
		mlx_do_sync(renderer->mlx);
}
