/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_next_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:14:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 19:15:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/vecmath.h>
#include <cub3d/map.h>
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

static t_image
	*_pick_texture(t_game_state *state, t_ray *ray)
{
	if (ray->type == RAY_HORIZONTAL)
	{
		if (ray->direction.x > 0)
			return (&state->asset_manager.south_texture);
		else
			return (&state->asset_manager.north_texture);
	}
	else
	{
		if (ray->direction.y > 0)
			return (&state->asset_manager.east_texture);
		else
			return (&state->asset_manager.west_texture);
	}
}

void
	_draw_column(t_game_state *state, t_ray *ray, int ray_index, int ray_count)
{
	double		vfov;
	t_int2		column_dimensions;
	t_int2		column_position;
	t_image		*texture;
	double		texture_step;
	double		texture_offset;
	t_double2	texture_position;
	t_color		color;

	texture = _pick_texture(state, ray);

	vfov = 2 * atan(tan(state->settings.fov * DEG2RAD / 2) * ((double)state->display.window.height / (double)state->display.window.width));

	column_dimensions.x = state->display.window.width / ray_count;
	column_dimensions.y = (double)state->display.window.height / ray->length / vfov;

	texture_step = (double)texture->height / (double)column_dimensions.y;
	texture_offset = 0;

	if ((size_t)column_dimensions.y > state->display.window.height)
	{
		texture_offset = (column_dimensions.y - state->display.window.height) / 2;
		column_dimensions.y = state->display.window.height;
	}


	column_position.x = column_dimensions.x * ray_index;
	column_position.y = state->display.window.height / 2 - column_dimensions.y / 2;

	texture_position.y = texture_offset * texture_step;

	if (ray->type == RAY_VERTICAL)
		texture_position.x = (double)texture->width
			* (ray->position.x - floor(ray->position.x));
	else
		texture_position.x = (double)texture->width
			* (ray->position.y - floor(ray->position.y));


	if ((ray->type == RAY_VERTICAL && ray->direction.y > 0) || (ray->type == RAY_HORIZONTAL && ray->direction.x < 0))
	{
		texture_position.x = texture->width - 1 - texture_position.x;
	}

	image_fill_rect(state->display.renderer.next_frame, state->asset_manager.ceiling_color, ft_int2(column_position.x, 0), ft_int2(column_position.x + column_dimensions.x, state->display.window.height / 2 - column_dimensions.y / 2));
	image_fill_rect(state->display.renderer.next_frame, state->asset_manager.floor_color, ft_int2(column_position.x, state->display.window.height / 2 + column_dimensions.y / 2), ft_int2(column_position.x + column_dimensions.x, state->display.window.height));

	int y = 0;
	while (y < column_dimensions.y)
	{
		color = *image_get_pixel(texture, texture_position.x, (size_t)texture_position.y);
		// color = 0xFF0000;

		if (ray->type == RAY_VERTICAL)
			color = color_multiply_all_components(color, 0.5);

		image_fill_rect(state->display.renderer.next_frame, color,
			ft_int2(column_position.x, column_position.y + y),
			ft_int2(column_position.x + column_dimensions.x, column_position.y + (y + 1)));

		y++;
		texture_position.y += texture_step;
	}
}

void
	draw_map_2d(t_game_state *state)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < state->map.height)
	{
		j = 0;
		while (j < state->map.width)
		{
			char value = map_get(&state->map, j, i);

			t_color color = value == '1' ? 0x4287f5 : 0x4d4d4d;

			image_fill_rect(state->display.renderer.next_frame, color, ft_int2(j * 40 + 1, i * 40 + 1), ft_int2((j + 1) * 40 - 1, (i + 1) * 40 - 1));
			j++;
		}
		i++;
	}
}

void
	game_render_next_frame(t_game_state *state)
{
	// (void)state;
	int			i;
	double		angle;
	double		angle_offset;
	t_double2	ray_direction;
	t_ray		ray;

	angle = -state->settings.fov / 2;
	angle_offset = state->settings.fov
		/ (state->display.window.width / state->settings.column_width);
	ray_direction = vec_rotate(state->player.direction, angle * DEG2RAD);
	i = 0;
	image_fill(state->display.renderer.current_frame, 0x000000);
	// draw_map_2d(state);
	while (angle < state->settings.fov / 2)
	{
		ray = cast_ray(state->player.position, ray_direction, 100,
				(t_ray_hit_predicate){(void *)_ray_hit_predicate, state});
		ray.length *= vec_dot(state->player.direction, ray_direction);
		ray.length = ft_absd(ray.length);
		_draw_column(state, &ray, i, state->settings.fov / angle_offset);
		// image_draw_line(state->display.renderer.next_frame, brush_circle(0xFF0000, 0), ft_int2(ray.origin.x * 40, ray.origin.y * 40), ft_int2( ray.position.x * 40, ray.position.y * 40 ));
		i++;
		angle += angle_offset;
		ray_direction = vec_rotate(state->player.direction, angle * DEG2RAD);
	}
	// image_fill_circle(state->display.renderer.next_frame, 0x00FF00, ft_int2(state->player.position.x * 40, state->player.position.y * 40), 10);
	renderer_render_next_frame(&state->display.renderer);
}
