/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_render_next_frame.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/03 03:04:21 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/window.h>
#include <cub3d/render/renderer.h>

#include <libft/math.h>

#include <mlx.h>

static void
	_update_frame_stats(t_renderer *renderer)
{
	renderer->frame_max = ft_maxd(renderer->frame_max, renderer->frame_delta);
	renderer->frame_min = ft_mind(renderer->frame_min, renderer->frame_delta);
	renderer->frame_avg = (renderer->frame_avg + renderer->frame_delta) / 2;
}

static void
	_update_frame_time(t_renderer *renderer)
{
	clock_t	time;

	time = clock();
	renderer->frame_delta = \
		(double)(time - renderer->prev_frame_clock) / CLOCKS_PER_SEC;
	if (renderer->prev_frame_clock > 0)
		_update_frame_stats(renderer);
	renderer->prev_frame_clock = time;
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
