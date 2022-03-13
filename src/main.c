/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 18:51:35 by bgenia           ###   ########.fr       */
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

// const int TILE_SIZE = 40;
const int TILE_SIZE = 1024;

const int MOUSE_DISTANCE = 50;

const t_color CEILING_COLOR = 0x0050fc;
const t_color FLOOR_COLOR = 0xf8fc00;

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

t_int2 position = {TILE_SIZE * 3, TILE_SIZE * 3};
double angle = 0;

const double SPEED = 50;

t_map map;

t_double2 direction = {0, 1};

t_image texture;

t_double2
	rotate_vector(t_double2 vector, double angle)
{
	return (ft_double2(
		vector.x * cos(angle) - vector.y * sin(angle),
		vector.x * sin(angle) + vector.y * cos(angle)
	));
}

double
	dot(t_double2 a, t_double2 b)
{
	return (a.x * b.x + a.y * b.y);
}

int
	handle_wasd(int key, t_window *window)
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
		direction = rotate_vector(direction, -(M_PI * 0.01));
	}
	if (key == XK_e)
	{
		direction = rotate_vector(direction, (M_PI * 0.01));
	}



	t_double2 front_collider = ft_double2(position.x + direction.x * 10, position.y + direction.y * 10);
	t_double2 back_collider = rotate_vector(front_collider, 180);
	t_double2 left_collider = rotate_vector(front_collider, 90);
	t_double2 right_collider = rotate_vector(front_collider, -90);


	if (key == XK_w)
	{
		if (
			map.vec_value[((int)front_collider.y / TILE_SIZE * map.witdth) + (int)front_collider.x / TILE_SIZE] == '#'
		)
			return 0;

		position.x += direction.x * SPEED;
		position.y += direction.y * SPEED;
	}
	if (key == XK_s)
	{
		if (
			map.vec_value[((int)back_collider.y / TILE_SIZE * map.witdth) + (int)back_collider.x / TILE_SIZE] == '#'
		)
			return 0;

		position.x -= direction.x * SPEED;
		position.y -= direction.y * SPEED;
	}
	if (key == XK_a)
	{
		if (
			map.vec_value[((int)left_collider.y / TILE_SIZE * map.witdth) + (int)left_collider.x / TILE_SIZE] == '#'
		)
			return 0;

		position.x -= direction.x * SPEED;
		position.y += direction.y * SPEED;
	}
	if (key == XK_d)
	{
		if (
			map.vec_value[((int)right_collider.y / TILE_SIZE * map.witdth) + (int)right_collider.x / TILE_SIZE] == '#'
		)
			return 0;

		position.x += direction.x * SPEED;
		position.y -= direction.y * SPEED;
	}
	return (0);
}

int
	handle_cursor(int x, int y, t_window *window)
{
	(void)window;
	// x -= window->width / 2;
	// y -= window->height / 2;

	// double h = hypot(x, y);

	// (void)h;
	// direction = ft_double2(x / h, y / h);

	(void)y;

	x -= window->height / 2;
	y = MOUSE_DISTANCE;

	double h = hypot(x, y);

	(void)h;
	direction = ft_double2(x / h, y / h);

	// double h1 = h * dot(direction1, direction);

	// direction = ft_double2(x / h1, y / h1);

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

# define DEG2RAD M_PI / 180

void
	draw3d(t_image *image, t_color color, double distance, int ray_index, int ray_count, t_double2 ray, t_double2 ray_direciton, bool side)
{
	int column_width = image->width / ray_count;

	int colomn_height = TILE_SIZE * image->height / distance;

	double texture_step = (double)texture.height / (double)colomn_height;
	double texture_offset = 0;

	if ((size_t)colomn_height > image->height)
	{
		texture_offset = (colomn_height - image->height) / 2;
		colomn_height = image->height;
	}


	int column_x = column_width * ray_index;
	int column_y = image->height / 2 - colomn_height / 2;

	// ft_printf("Col: %d %d %d %d\n", column_width, colomn_height, column_x, column_y);

	(void)texture_offset;

	double texture_y = texture_offset * texture_step;

	double side_pos = side ? ray.x : ray.y;

	double texture_x = (double)((int)side_pos % TILE_SIZE) * ((double)texture.width / (double)TILE_SIZE);
	if ((side && ray_direciton.y > 0) || (!side && ray_direciton.x < 0))
	{
		texture_x = texture.width - 1 - texture_x;
	}

	(void)ray_direciton;

	image_fill_rect(image, CEILING_COLOR, ft_int2(column_x, 0), ft_int2(column_x + column_width, image->height / 2));
	image_fill_rect(image, FLOOR_COLOR, ft_int2(column_x, image->height / 2), ft_int2(column_x + column_width, image->height));

	(void)color;
	int y = 0;
	while (y < colomn_height)
	{
		t_color color = *image_get_pixel(&texture, texture_x, (size_t)texture_y);

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

void
	draw_rays(t_image *image)
{
	int	i;

	double fov = 60;
	double angle = -fov / 2;
	double change = fov / (image->width / COLUMN_WIDTH);

	t_double2 ray_direction = rotate_vector(direction, angle * DEG2RAD);

	i = 0;
	while (angle < fov / 2)
	{
		double _nctg = -(ray_direction.x / ray_direction.y); // -ctg

		t_double2 rayY;
		t_double2 offset;

		double lengthY = 0;

		if (ray_direction.y < 0)
		{
			rayY.y = position.y / TILE_SIZE * TILE_SIZE - 0.0001;
			rayY.x = (position.y - rayY.y) * _nctg + position.x;
			offset.y = -TILE_SIZE;
			offset.x = -offset.y * _nctg;
		}
		if (ray_direction.y > 0)
		{
			rayY.y = position.y / TILE_SIZE * TILE_SIZE + TILE_SIZE;
			rayY.x = (position.y - rayY.y) * _nctg + position.x;
			offset.y = TILE_SIZE;
			offset.x = -offset.y * _nctg;
		}
		size_t dof = 0;
		if (ray_direction.y == 0)
		{
			rayY = ft_double2(position.x, position.y);
			dof = map.height;
			lengthY = INFINITY;
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

		if (lengthY < INFINITY)
			lengthY = hypot(rayY.x - position.x, rayY.y - position.y);

		double _ntan = -(ray_direction.y / ray_direction.x); // -tg

		t_double2 rayX;

		double lengthX = 0;

		if (ray_direction.x < 0)
		{
			rayX.x = position.x / TILE_SIZE * TILE_SIZE - 0.0001;
			rayX.y = (position.x - rayX.x) * _ntan + position.y;
			offset.x = -TILE_SIZE;
			offset.y = -offset.x * _ntan;
		}
		if (ray_direction.x > 0)
		{
			rayX.x = position.x / TILE_SIZE * TILE_SIZE + TILE_SIZE;
			rayX.y = (position.x - rayX.x) * _ntan + position.y;
			offset.x = TILE_SIZE;
			offset.y = -offset.x * _ntan;
		}
		dof = 0;
		if (ray_direction.x == 0)
		{
			rayX = ft_double2(position.x, position.y);
			dof = map.witdth;
			lengthX = INFINITY;
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

		if (lengthX < INFINITY)
			lengthX = hypot(rayX.x - position.x, rayX.y - position.y);

		t_double2 ray = lengthX > lengthY ? rayY : rayX;

		// image_draw_line(image, brush_circle(0xFF3333, 0), position, ft_int2(ray.x, ray.y));

		double distance = ft_mind(lengthX, lengthY);

		double cos_phi = dot(direction, ray_direction);

		distance *= cos_phi;

		// double direction1 = acos(ray_direction.x);
		// double direction2 = asin(ray_direction.y);

		// ft_printf(">> %f %f \n", direction1, direction2);

		// double ca =

		t_color color;

		if (lengthX > lengthY)
			color = 0x9c9c9c;
		else
			color = 0x696969;

		(void)distance, (void)image;
		draw3d(image, color, distance, i, fov / change, ray, ray_direction, lengthX > lengthY);

		i++;
		angle += change;
		ray_direction = rotate_vector(direction, angle * DEG2RAD);
	}
}

int
	handle_frame(t_window *window)
{
	// Clear frame
	image_fill(next_frame, 0xe6e6e6);

	// draw_map(next_frame, &map);

	// t_int2 view_direction = ft_int2(direction.x * 30 + position.x, direction.y * 30 + position.y);

	// ft_printf(">> %f %f\n", direction.x, direction.y);

	draw_rays(next_frame);

	// Draw direction
	// image_draw_line(next_frame, brush_circle(0xde1f1f, 2), position, view_direction);

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
	image_destroy(&texture);

	mlx_destroy_display(mlx);
	free(mlx);

	map_destroy(&map);

	return (0);
}
