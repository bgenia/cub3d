/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 12:32:46 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <cub3d/map/map.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/window.h>
#include <cub3d/render/graphics.h>

#include <libft/libft.h>

#include <mlx.h>

#include <X11/X.h>
#include <X11/keysym.h>

const int W_WIDTH = 960;
const int W_HEIGHT = 720;

const int TILE_SIZE = 40;

void
	init_map(t_map *map)
{
	map_add_line(map, "########################");
	map_add_line(map, "#....#.................#");
	map_add_line(map, "#.........#.......#....#");
	map_add_line(map, "#....#....#......###...#");
	map_add_line(map, "############......#...##");
	map_add_line(map, "#.....#...#............#");
	map_add_line(map, "#..............#....####");
	map_add_line(map, "####.....#.....#.......#");
	map_add_line(map, "#........###...####....#");
	map_add_line(map, "#.....####.....#.......#");
	map_add_line(map, "#........#.....#.......#");
	map_add_line(map, "#.#####................#");
	map_add_line(map, "#.#...###......#..#....#");
	map_add_line(map, "#.#..........###..#....#");
	map_add_line(map, "#.#...###......#..#....#");
	map_add_line(map, "#.#####.....#..........#");
	map_add_line(map, "#...........#..#..#....#");
	map_add_line(map, "########################");
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

t_int2 position = {0, 0};
double angle = 0;

const double SPEED = 10;

t_map map;

int
	handle_wasd(int key, t_window *window)
{
	(void)window;
	if (key == XK_w)
		position.y -= SPEED;
	if (key == XK_a)
		position.x -= SPEED;
	if (key == XK_s)
		position.y += SPEED;
	if (key == XK_d)
		position.x += SPEED;
	return (0);
}

t_double2 direction = {0, 1};

int
	handle_cursor(int x, int y, t_window *window)
{
	(void)window;
	x -= position.x;
	y -= position.y;

	double h = hypot(x, y);

	direction = ft_double2(x / h, y / h);

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
		while (j < map->witdth)
		{
			char value = map->vec_value[i * map->witdth + j];

			t_color color = value == '#' ? 0x4287f5 : 0x4d4d4d;

			image_fill_rect(image, color, ft_int2(j * TILE_SIZE + 1, i * TILE_SIZE + 1), ft_int2((j + 1) * TILE_SIZE - 1, (i + 1) * TILE_SIZE - 1));
			j++;
		}
		i++;
	}
}

void
	draw_rays(t_image *image)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		double _tan = direction.y / direction.x;
		double _atan = -1 / _tan;

		t_double2 rayY;
		t_double2 offset;

		if (direction.y < 0)
		{
			rayY.y = position.y / TILE_SIZE * TILE_SIZE - 0.0001;
			rayY.x = (position.y - rayY.y) * _atan + position.x;
			offset.y = -TILE_SIZE;
			offset.x = -offset.y * _atan;
		}
		if (direction.y > 0)
		{
			rayY.y = position.y / TILE_SIZE * TILE_SIZE + TILE_SIZE;
			rayY.x = (position.y - rayY.y) * _atan + position.x;
			offset.y = TILE_SIZE;
			offset.x = -offset.y * _atan;
		}
		size_t dof = 0;
		if (direction.y == 0)
		{
			rayY = ft_double2(position.x, position.y);
			dof = map.height;
		}
		while (dof < map.height)
		{
			t_int2 map_pos = ft_int2(rayY.x / TILE_SIZE, rayY.y / TILE_SIZE);
			size_t map_index = map_pos.y * map.witdth + map_pos.x;
			if (map_index >= 0 && map_index < map.height * map.witdth && map.vec_value[map_index] == '#')
			{
				dof = map.height;
			}
			else
			{
				rayY.x += offset.x;
				rayY.y += offset.y;
				dof += 1;
			}
		}
		// image_draw_line(image, brush_circle(0xFF0000, 3), position, ft_int2(rayY.x, rayY.y));

		double lengthY = hypot(rayY.x - position.x, rayY.y - position.y);

		double _ntan = -_tan;

		t_double2 rayX;

		if (direction.x < 0)
		{
			rayX.x = position.x / TILE_SIZE * TILE_SIZE - 0.0001;
			rayX.y = (position.x - rayX.x) * _ntan + position.y;
			offset.x = -TILE_SIZE;
			offset.y = -offset.x * _ntan;
		}
		if (direction.x > 0)
		{
			rayX.x = position.x / TILE_SIZE * TILE_SIZE + TILE_SIZE;
			rayX.y = (position.x - rayX.x) * _ntan + position.y;
			offset.x = TILE_SIZE;
			offset.y = -offset.x * _ntan;
		}
		dof = 0;
		if (direction.x == 0)
		{
			rayX = ft_double2(position.x, position.y);
			dof = map.witdth;
		}
		while (dof < map.height)
		{
			t_int2 map_pos = ft_int2(rayX.x / TILE_SIZE, rayX.y / TILE_SIZE);
			size_t map_index = map_pos.y * map.witdth + map_pos.x;
			if (map_index >= 0 && map_index < map.height * map.witdth && map.vec_value[map_index] == '#')
			{
				dof = map.height;
			}
			else
			{
				rayX.x += offset.x;
				rayX.y += offset.y;
				dof += 1;
			}
		}
		// image_draw_line(image, brush_circle(0x00FF00, 2), position, ft_int2(rayX.x, rayX.y));

		double lengthX = hypot(rayX.x - position.x, rayX.y - position.y);

		t_double2 ray = lengthX > lengthY ? rayY : rayX;

		image_draw_line(image, brush_circle(0x00FF00, 2), position, ft_int2(ray.x, ray.y));

		i++;
	}
}

int
	handle_frame(t_window *window)
{
	// Clear frame
	image_fill(next_frame, 0xe6e6e6);

	draw_map(next_frame, &map);

	// t_int2 view_direction = ft_int2(direction.x * 30 + position.x, direction.y * 30 + position.y);

	// ft_printf(">> %f %f\n", direction.x, direction.y);

	draw_rays(next_frame);

	// Draw direction
	// image_draw_line(next_frame, brush_circle(0xde1f1f, 2), position, view_direction);

	// Draw player
	image_fill_circle(next_frame, 0x00b309, position, 10);
	image_draw_circle(next_frame, brush_circle(0x154d18, 2), position, 10);


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

	t_window window = window_create(mlx, W_WIDTH, W_HEIGHT, "cub3demo!");

	map = map_create(24, 18);

	init_map(&map);

	mlx_hook(window.mlx_window, DestroyNotify, None, handle_exit, &window);
	mlx_hook(window.mlx_window, KeyRelease, KeyReleaseMask, handle_backspace, &window);
	mlx_hook(window.mlx_window, KeyPress, KeyPressMask, handle_wasd, &window);
	mlx_hook(window.mlx_window, MotionNotify, PointerMotionMask, handle_cursor, &window);
	mlx_loop_hook(mlx, handle_frame, &window);

	t_image frame1 = image_create(mlx, window.width, window.height);
	t_image frame2 = image_create(mlx, window.width, window.height);

	current_frame = &frame1;
	next_frame = &frame2;

	mlx_loop(mlx);

	window_destroy(&window);

	image_destroy(&frame1);
	image_destroy(&frame2);

	mlx_destroy_display(mlx);
	free(mlx);

	map_destroy(&map);

	return (0);
}
