/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_render_next_frame.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 22:18:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/time.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>

#include <mlx.h>

static void
	_update_frame_time(t_renderer *renderer)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	renderer->frame_delta = timeval.tv_usec - renderer->prev_frame_time;
	renderer->prev_frame_time = timeval.tv_usec;
}

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
	_update_frame_time(renderer);
}
