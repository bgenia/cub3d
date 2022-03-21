/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_render_next_frame.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 23:28:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>

#include <mlx.h>

static uint64_t
	_get_time_ms(void)
{
	struct timeval	timeval;
	uint64_t		result;

	gettimeofday(&timeval, NULL);
	result = timeval.tv_sec * 1000;
	result += timeval.tv_usec / 1000;
	return (result);
}

static void
	_update_frame_time(t_renderer *renderer)
{
	uint64_t	time;

	time = _get_time_ms();
	renderer->frame_delta = (double)(time - renderer->prev_frame_time) / 1000;
	renderer->prev_frame_time = time;
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
