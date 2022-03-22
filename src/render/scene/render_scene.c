/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:57:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 18:33:45 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/render/render.h>
#include <cub3d/vecmath.h>
#include <cub3d/level/map.h>
#include <cub3d/raycasting/ray.h>
#include <cub3d/raycasting/raycaster.h>
#include <cub3d/raycasting/raycasting_utils.h>
#include <cub3d/graphics/color.h>
#include <cub3d/graphics/drawing.h>
#include <cub3d/render/scene.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>
#include <libft/math.h>
#include <libft/array.h>

static void
	_save_to_depth_buffer(t_game_state *state, t_ray *ray, int ray_index)
{
	state->display.depth_buffer[ray_index] = *ray;
	state->display.depth_indices[ray_index] = ray_index;
}

static int
	_depth_buffer_index_comparator(
		int *a,
		int *b,
		t_ray *depth_buffer,
		size_t element_size
	)
{
	double	result;

	(void)element_size;
	result = depth_buffer[*a].length - depth_buffer[*b].length;
	return (ft_clampd(result, -1, 1));
}

static void
	_sort_depth_buffer(t_game_state *state)
{
	ft_qsort(
		state->display.depth_indices,
		sizeof(int),
		state->display.ray_count,
		(t_qsort_comparator){
		.comaprator = (void *)_depth_buffer_index_comparator,
		.arg = state->display.depth_buffer
	});
}

static void
	_fill_depth_buffer(t_game_state *state)
{
	t_raycaster	raycaster;
	int			iteration_limit;
	t_ray		ray;

	raycaster = raycaster_create(
			state->player.position,
			state->player.direction,
			ft_deg2rad(state->settings.fov),
			state->display.window.width / state->settings.column_width
			);
	iteration_limit = ft_max(state->map.width, state->map.height);
	while (!raycaster.done)
	{
		ray = raycaster_cast_ray(&raycaster, iteration_limit,
				(t_ray_hit_predicate){(void *)check_ray_wall_hit, &state->map});
		_save_to_depth_buffer(state, &ray, raycaster.ray_index);
		raycaster_update_angle(&raycaster);
	}
}

void
	render_scene(t_game_state *state)
{
	int		i;
	int		ray_index;
	t_ray	*ray;

	_fill_depth_buffer(state);
	_sort_depth_buffer(state);
	i = 0;
	while (i < state->display.ray_count)
	{
		ray_index = state->display.depth_indices[i];
		ray = &state->display.depth_buffer[ray_index];
		render_column(state, ray, ray_index, state->display.ray_count);
		i++;
	}
}
