/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 15:51:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <cub3d/map.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/window.h>
#include <cub3d/render/graphics.h>
#include <cub3d/render/raycasting.h>

#include <cub3d/vecmath.h>

#include <libft/libft.h>

#include <mlx.h>

#include <X11/X.h>
#include <X11/keysym.h>

const int W_WIDTH = 960;
const int W_HEIGHT = 720;

// const int TILE_SIZE = 40;
const int TILE_SIZE = 40;

const int MOUSE_DISTANCE = 50;

const t_color CEILING_COLOR = 0x0050fc;
const t_color FLOOR_COLOR = 0xf8fc00;

# define DEG2RAD M_PI / 180

void
	init_map(t_map *map)
{
	map_push_line(map, "########################");
	map_push_line(map, "#....#.................#");
	map_push_line(map, "#.........#.......#....#");
	map_push_line(map, "#....#....#......###...#");
	map_push_line(map, "############......#...##");
	map_push_line(map, "#.....#...#............#");
	map_push_line(map, "#..............#....####");
	map_push_line(map, "####.....#.....#.......#");
	map_push_line(map, "#........###...####....#");
	map_push_line(map, "#.....####.....#.......#");
	map_push_line(map, "#........#.....#.......#");
	map_push_line(map, "#.#####................#");
	map_push_line(map, "#.#...###......#..#....#");
	map_push_line(map, "#.#..........###..#....#");
	map_push_line(map, "#.#...###......#..#....#");
	map_push_line(map, "#.#####.....#..........#");
	map_push_line(map, "#...........#..#..#....#");
	map_push_line(map, "########################");
}

int
	handle_exit(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

int
	handle_backspace(int key, t_window *window)
{
	if (key == XK_BackSpace)
		return (handle_exit(window));
	return (0);
}

t_int2 position = {TILE_SIZE * 3, TILE_SIZE * 3};
double angle = 0;

const double SPEED = 3;

t_map map;

t_double2 direction = {0, 1};

t_image texture;

int
	handle_keys(int key, t_window *window)
{
	(void)window;

	// t_int2 mouse;

	// mlx_mouse_get_pos(window->mlx, window->mlx_window, &mouse.x, &mouse.y);

	// mouse.x -= window->width / 2;
	// mouse.y -= window->height / 2;

	// double h = hypot(mouse.x, mouse.y);

	// if (h >= 1)
	// 	direction = ft_double2(mouse.x / h, mouse.y / h);

	if (key == XK_q)
	{
		direction = vec_rotate(direction, -(M_PI * 0.01));
	}
	if (key == XK_e)
	{
		direction = vec_rotate(direction, (M_PI * 0.01));
	}



	t_double2 front_collider = ft_double2(position.x + direction.x * 10, position.y + direction.y * 10);
	t_double2 back_collider = vec_rotate(front_collider, 180 * DEG2RAD);
	t_double2 left_collider = vec_rotate(front_collider, 90 * DEG2RAD);
	t_double2 right_collider = vec_rotate(front_collider, -90 * DEG2RAD);

	t_double2 side_dir = vec_rotate(direction, M_PI / 2);


	if (key == XK_w)
	{
		if (
			map_get(&map, (int)front_collider.x / TILE_SIZE, (int)front_collider.y / TILE_SIZE) == '#'
		)
			return 0;

		position.x += direction.x * SPEED;
		position.y += direction.y * SPEED;
	}
	if (key == XK_s)
	{
		if (
			map_get(&map, (int)back_collider.x / TILE_SIZE, (int)back_collider.y / TILE_SIZE) == '#'
		)
			return 0;

		position.x -= direction.x * SPEED;
		position.y -= direction.y * SPEED;
	}
	if (key == XK_a)
	{
		if (
			map_get(&map, (int)left_collider.x / TILE_SIZE, (int)left_collider.y / TILE_SIZE) == '#'
		)
			return 0;

		position.x -= side_dir.x * SPEED;
		position.y -= side_dir.y * SPEED;
	}
	if (key == XK_d)
	{
		if (
			map_get(&map, (int)right_collider.x / TILE_SIZE, (int)right_collider.y / TILE_SIZE) == '#'
		)
			return 0;

		position.x += side_dir.x * SPEED;
		position.y += side_dir.y * SPEED;
	}
	return (0);
}

t_image *current_frame;
t_image *next_frame;

void
	draw_map(t_image *image, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			char value = map_get(map, j, i);

			t_color color = value == '#' ? 0x4287f5 : 0x4d4d4d;

			image_fill_rect(image, color, ft_int2(j * TILE_SIZE + 1, i * TILE_SIZE + 1), ft_int2((j + 1) * TILE_SIZE - 1, (i + 1) * TILE_SIZE - 1));
			j++;
		}
		i++;
	}
}

void
	draw3d(t_image *image, t_ray *ray, double fov, int ray_index, int ray_count)
{
	double vfov = 2 * atan(tan(fov * DEG2RAD / 2) * ((double)image->height / (double)image->width));

	int column_width = image->width / ray_count;

	// int column_height = image->height / ray->length;
	// int column_height = image->height / ray->length / (fov / 60) * ((double)image->width / (double)image->height);
	int column_height = image->height / ray->length / vfov;

	double texture_step = (double)texture.height / (double)column_height;
	double texture_offset = 0;

	if ((size_t)column_height > image->height)
	{
		texture_offset = (column_height - image->height) / 2;
		column_height = image->height;
	}


	int column_x = column_width * ray_index;
	int column_y = image->height / 2 - column_height / 2;

	// ft_printf("Col: %d %d %d %d\n", column_width, colomn_height, column_x, column_y);

	(void)texture_offset, (void)fov;

	double texture_y = texture_offset * texture_step;

	bool side = ray->type == RAY_VERTICAL;

	double side_pos = side ? ray->position.x : ray->position.y;

	double texture_x = texture.width * (side_pos - floor(side_pos));
	if ((side && ray->direction.y > 0) || (!side && ray->direction.x < 0))
	{
		texture_x = texture.width - 1 - texture_x;
	}


	image_fill_rect(image, CEILING_COLOR, ft_int2(column_x, 0), ft_int2(column_x + column_width, image->height / 2 - column_height / 2));
	image_fill_rect(image, FLOOR_COLOR, ft_int2(column_x, image->height / 2 + column_height / 2), ft_int2(column_x + column_width, image->height));

	int y = 0;
	while (y < column_height)
	{
		t_color color = *image_get_pixel(&texture, texture_x, (size_t)texture_y);

		// t_color color = 0xF0F0F0;

		if (side)
			color = color_multiply_all_components(color, 0.5);

		image_fill_rect(image, color,
			ft_int2(column_x, column_y + y),
			ft_int2(column_x + column_width, column_y + (y + 1)));
		y++;
		texture_y += texture_step;
	}

	// image_fill_rect(image, color, ft_int2(column_x, column_y), ft_int2(column_x + column_width, column_y + colomn_height));
}

# define COLUMN_WIDTH 1

bool
	ray_hit_predicate(t_double2 hit_position, t_map *my_map)
{
	return (map_get(my_map, hit_position.x, hit_position.y) == '#');
}

void
	draw_rays(t_image *image)
{
	int	i;

	double fov = 75;
	double angle = -fov / 2;
	double change = fov / (image->width / COLUMN_WIDTH);

	t_double2 ray_direction = vec_rotate(direction, angle * DEG2RAD);

	t_double2 origin = ft_double2(position.x, position.y);
	origin = vec_scale(origin, (double)1 / (double)TILE_SIZE);

	i = 0;
	while (angle < fov / 2)
	{

		t_ray ray = cast_ray(origin, ray_direction, map.width, (t_ray_hit_predicate){ .predicate = (void *)ray_hit_predicate, .arg = &map });

		ray.length *= vec_dot(direction, ray.direction);

		// image_draw_line(image, brush_circle(0xFF0000, 0), position, ft_int2( ray.position.x * TILE_SIZE, ray.position.y * TILE_SIZE ));

		draw3d(image, &ray, fov, i, fov / change);

		i++;
		angle += change;
		ray_direction = vec_rotate(direction, angle * DEG2RAD);
	}
}

int
	handle_frame(t_window *window)
{
	// Clear frame
	// image_fill(next_frame, 0xe6e6e6);

	// draw_map(next_frame, &map);

	// t_int2 view_direction = ft_int2(direction.x * 30 + position.x, direction.y * 30 + position.y);

	// ft_printf(">> %f %f\n", direction.x, direction.y);

	draw_rays(next_frame);

	// ft_printf(">> %d %d -> %f %f\n", position.x, position.y, direction.x, direction.y);

	// Draw direction
	// image_draw_line(next_frame, brush_circle(0x00FF00, 2), position, ft_int2(position.x +  direction.x * 30, position.y + direction.y * 30));

	// Draw player
	// image_fill_circle(next_frame, 0x00b309, position, 10);
	// image_draw_circle(next_frame, brush_circle(0x154d18, 2), position, 10);


	window_draw_image(window, next_frame);

	void *temp = current_frame;
	current_frame = next_frame;
	next_frame = temp;

	mlx_do_sync(window->mlx);

	return (0);
}

int
	main(void)
{
	void *mlx = mlx_init();

	texture = image_load_xpm_file(mlx, "assets/textures/niko.xpm");

	t_window window = window_create(mlx, W_WIDTH, W_HEIGHT, "cub3demo!");

	map = map_create();

	init_map(&map);

	mlx_hook(window.mlx_window, DestroyNotify, None, handle_exit, &window);
	mlx_hook(window.mlx_window, KeyRelease, KeyReleaseMask, handle_backspace, &window);
	mlx_hook(window.mlx_window, KeyPress, KeyPressMask, handle_keys, &window);
	// mlx_hook(window.mlx_window, MotionNotify, PointerMotionMask, handle_cursor, &window);
	mlx_loop_hook(mlx, handle_frame, &window);

	t_image frame1 = image_create(mlx, window.width, window.height);
	t_image frame2 = image_create(mlx, window.width, window.height);

	current_frame = &frame1;
	next_frame = &frame2;

	mlx_loop(mlx);

	window_destroy(&window);

	image_destroy(&frame1);
	image_destroy(&frame2);
	image_destroy(&texture);

	mlx_destroy_display(mlx);
	free(mlx);

	map_destroy(&map);

	return (0);
}
