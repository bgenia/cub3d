/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:23:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/game/render.h>
#include <cub3d/vecmath.h>
#include <cub3d/level/map.h>
#include <cub3d/render/raycasting.h>
#include <cub3d/render/color.h>
#include <cub3d/render/graphics.h>

#include <libft/io/printf.h>
#include <libft/tuples.h>
#include <libft/math.h>

static bool
	_ray_hit_predicate(t_double2 hit_position, t_game_state *state)
{
	return (map_get(&state->map, hit_position.x, hit_position.y) == '1');
}

void
	game_render_next_frame(t_game_state *state)
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
				(t_ray_hit_predicate){(void *)_ray_hit_predicate, state});
		ray.length *= vec_dot(state->player.direction, ray_direction);
		ray.length = ft_absd(ray.length);
		game_render_column(state, &ray, i, state->settings.fov / angle_offset);
		i++;
		angle += angle_offset;
		ray_direction = vec_rotate(state->player.direction, ft_deg2rad(angle));
	}
	renderer_render_next_frame(&state->display.renderer);
}
