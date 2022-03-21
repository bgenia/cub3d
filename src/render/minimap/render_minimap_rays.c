/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_rays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:31:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 19:23:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/settings.h>
#include <cub3d/game/game.h>
#include <cub3d/graphics/image.h>
#include <cub3d/raycasting/raycasting.h>
#include <cub3d/raycasting/raycasting_utils.h>
#include <cub3d/vecmath.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>
#include <libft/math.h>

#include <libft/io/printf.h>

static void
	_draw_minimap_ray(t_game_state *state, t_ray *ray)
{
	int			map_size;
	t_double2	position;

	map_size = state->settings.minimap.size;
	position = ray->position;
	position.x -= state->player.position.x;
	position.y -= state->player.position.y;
	position = vec_scale(position, state->settings.minimap.scale);
	position.x += state->settings.minimap.size / 2;
	position.y += state->settings.minimap.size / 2;
	image_draw_line(&state->display.minimap, brush_circle(MINIMAP_COLOR_RAY, 0),
		ft_int2(map_size / 2, map_size / 2),
		ft_int2(position.x, position.y));
}

void
	render_minimap_rays(t_game_state *state)
{
	int			i;
	double		angle;
	double		angle_offset;
	t_double2	ray_direction;
	t_ray		ray;

	angle = -state->settings.fov / 2;
	angle_offset = state->settings.fov / state->settings.minimap.ray_count;
	ray_direction = vec_rotate(state->player.direction, ft_deg2rad(angle));
	i = 0;
	while (angle < state->settings.fov / 2)
	{
		ray = cast_ray(state->player.position, ray_direction,
				state->settings.minimap.size / state->settings.minimap.scale,
				(t_ray_hit_predicate){(void *)check_ray_wall_hit, &state->map});
		_draw_minimap_ray(state, &ray);
		i++;
		angle += angle_offset;
		ray_direction = vec_rotate(state->player.direction, ft_deg2rad(angle));
	}
}
