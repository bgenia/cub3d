/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_load_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:27:21 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/18 22:13:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <cub3d/level/map.h>
#include <cub3d/level/level.h>
#include <cub3d/level/assets.h>

#include <libft/string/string.h>
#include <libft/memory/memory.h>
#include <libft/io/reader.h>
#include <libft/io/fdstream.h>
#include <libft/utils.h>

static char
	*_check_fill_data(t_assets *assets)
{
	if (assets->north_texture_path == NULL)
		return ("At least there is no NO");
	if (assets->south_texture_path == NULL)
		return ("At least there is no SO");
	if (assets->west_texture_path == NULL)
		return ("At least there is no WE");
	if (assets->east_texture_path == NULL)
		return ("At least there is no EA");
	if (assets->ceiling_color == NULL)
		return ("At least there is no C");
	if (assets->floor_color == NULL)
		return ("At least there is no F");
	return (NULL);
}

static void
	_try_parse_asset(t_assets *assets, char *line)
{
	char	**b;

	b = ft_smsplit(line, ' ');
	if (ft_strcmp(b[0], "NO") == 0)
		assets->north_texture_path = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "SO") == 0)
		assets->south_texture_path = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "WE") == 0)
		assets->west_texture_path = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "EA") == 0)
		assets->east_texture_path = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "F") == 0)
		assets->floor_color = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "C") == 0)
		assets->ceiling_color = ft_strdup(b[1]);
	else
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nExtra characters\n");
	free(b);
}

static void
	_init_map(t_level *level, t_stream *istream)
{
	t_reader	reader;
	char		*line;

	reader = ft_reader_create(istream, 1024);
	line = ft_reader_read_line(&reader);
	while (1 == 1)
	{
		if (line[0] && _check_fill_data(&level->assets))
			_try_parse_asset(&level->assets, line);
		else if (line[0] != '\0')
			map_push_line(&level->map, line);
		free(line);
		if (reader.status == READER_EOF)
			break ;
		line = ft_reader_read_line(&reader);
	}
	ft_reader_destroy(&reader);
	if (_check_fill_data(&level->assets))
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\n%s\n",
			_check_fill_data(&level->assets));
}

t_level
	level_load_from_file(char *path)
{
	t_level		level;
	t_stream	stream;

	if (!validate_level_file_extension(path))
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\n"
			"Wrong extension (must be .cub)\n");
	stream = ft_stream_open_fd(open(path, O_RDONLY), STREAM_MODE_I, true);
	if (!ft_stream_is_valid(&stream))
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nCannot open file\n");
	level.map = map_create();
	level.assets = (t_assets){0};
	_init_map(&level, &stream);
	ft_stream_close(&stream);
	return (level);
}
