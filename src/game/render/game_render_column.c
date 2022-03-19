/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/19 11:21:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>
#include <cub3d/render/raycasting.h>
#include <cub3d/game/game.h>
#include <cub3d/game/render.h>
#include <cub3d/vecmath.h>

#include <libft/tuples.h>
#include <libft/math.h>

typedef struct s_column_render_vars
{
	t_int2		column_dimensions;
	t_int2		column_position;
	t_image		*texture;
	double		texture_step;
	double		texture_offset;
	t_double2	texture_position;
	t_int2		texture_resolution;
	t_double2	texture_scaling;
}	t_column_render_vars;

static t_int2
	_compute_column_dimensions(t_game_state *state, t_ray *ray, int ray_count)
{
	t_int2	column_dimensions;
	double	vfov;

	vfov = 2 * atan(tan(ft_deg2rad(state->settings.fov) / 2)
			* ((double)state->display.window.height
				/ (double)state->display.window.width));
	column_dimensions = ft_int2(
			state->display.window.width / ray_count,
			(double)state->display.window.height / ray->length / vfov
			);
	return (column_dimensions);
}

static t_double2
	_compute_texture_position(t_ray *ray, t_column_render_vars *vars)
{
	t_double2	texture_position;

	texture_position.y = vars->texture_offset * vars->texture_step;
	if (ray->type == RAY_VERTICAL)
		texture_position.x = (double)vars->texture_resolution.x
			* (ray->position.x - floor(ray->position.x));
	else
		texture_position.x = (double)vars->texture_resolution.x
			* (ray->position.y - floor(ray->position.y));
	if ((ray->type == RAY_VERTICAL && ray->direction.y > 0)
		|| (ray->type == RAY_HORIZONTAL && ray->direction.x < 0))
		texture_position.x = vars->texture_resolution.x - 1 - texture_position.x;
	return (texture_position);
}

static void
	_render_background(t_game_state *state, t_column_render_vars *vars)
{
	image_fill_rect(
		state->display.renderer.next_frame,
		state->asset_manager.ceiling_color,
		ft_int2(vars->column_position.x, 0),
		ft_int2(
			vars->column_position.x + vars->column_dimensions.x,
			state->display.window.height / 2 - vars->column_dimensions.y / 2
			)
		);
	image_fill_rect(
		state->display.renderer.next_frame,
		state->asset_manager.floor_color,
		ft_int2(
			vars->column_position.x,
			state->display.window.height / 2 + vars->column_dimensions.y / 2
			),
		ft_int2(
			vars->column_position.x + vars->column_dimensions.x,
			state->display.window.height
			)
		);
}

static void
	_render_column(t_game_state *state, t_ray *ray, t_column_render_vars *vars)
{
	t_color	color;
	int		y;
	double	y_scaling;

	y_scaling = (double)vars->texture_resolution.y / (double)vars->texture->height;
	y = 0;
	while (y < vars->column_dimensions.y)
	{
		color = *image_get_pixel(vars->texture,
				ft_mapd(floor(vars->texture_position.x), vars->texture_resolution.x, vars->texture->width),
				ft_mapd(floor(vars->texture_position.y * y_scaling), vars->texture_resolution.y, vars->texture->height));
		if (ray->type == RAY_VERTICAL)
			color = color_multiply_all_components(color, 0.5);
		image_fill_rect(state->display.renderer.next_frame, color,
			ft_int2(vars->column_position.x, vars->column_position.y + y),
			ft_int2(
				vars->column_position.x + vars->column_dimensions.x,
				vars->column_position.y + (y + 1)));
		y++;
		vars->texture_position.y += vars->texture_step;
	}
}

void
	game_render_column(
		t_game_state *state,
		t_ray *ray,
		int ray_index,
		int ray_count
	)
{
	t_column_render_vars	vars;

	vars.column_dimensions = _compute_column_dimensions(state, ray, ray_count);
	vars.texture = pick_texture(state, ray);
	vars.texture_step = \
		(double)vars.texture->height / (double)vars.column_dimensions.y;
	vars.texture_offset = 0;
	vars.texture_resolution = state->settings.texture_resolution;
	if ((size_t)vars.column_dimensions.y > state->display.window.height)
	{
		vars.texture_offset = \
			(vars.column_dimensions.y - state->display.window.height) / 2;
		vars.column_dimensions.y = state->display.window.height;
	}
	vars.column_position = ft_int2(
			vars.column_dimensions.x * ray_index,
			state->display.window.height / 2 - vars.column_dimensions.y / 2
			);
	vars.texture_position = _compute_texture_position(ray, &vars);
	_render_background(state, &vars);
	_render_column(state, ray, &vars);
}
