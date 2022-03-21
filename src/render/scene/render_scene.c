/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:57:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 17:49:47 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/render/render.h>
#include <cub3d/vecmath.h>
#include <cub3d/level/map.h>
#include <cub3d/raycasting/raycasting.h>
#include <cub3d/raycasting/raycasting_utils.h>
#include <cub3d/graphics/color.h>
#include <cub3d/graphics/drawing.h>
#include <cub3d/render/scene.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>
#include <libft/math.h>

void
	render_scene(t_game_state *state)
{
	int			i;
	double		angle;
	double		angle_offset;
	t_double2	ray_direction;
	t_ray		ray;

	angle = -state->settings.fov / 2;
	angle_offset = state->settings.fov
		/ (state->display.window.width / state->settings.column_width);
	ray_direction = vec_rotate(state->player.direction, ft_deg2rad(angle));
	i = 0;
	while (angle < state->settings.fov / 2)
	{
		ray = cast_ray(state->player.position, ray_direction,
				ft_max(state->map.width, state->map.height),
				(t_ray_hit_predicate){(void *)check_ray_wall_hit, &state->map});
		render_column(state, &ray, i, state->settings.fov / angle_offset);
		i++;
		angle += angle_offset;
		ray_direction = vec_rotate(state->player.direction, ft_deg2rad(angle));
	}
}
