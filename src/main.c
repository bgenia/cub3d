/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:20:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 22:19:58 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <cub3d/parser.h>

#include <libft/utils.h>
#include <libft/io/printf.h>
#include <cub3d/check_map.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_cub_file	cub_file;

	if (argc != 2)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\n%s\n", "Where is a map?");
	fd = open(argv[1], __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_exitf(STDERR_FILENO, EXIT_FAILURE,
			"Error\n%s\n", "Directory, not a file");
	}
	cub_file = parse_cub_file(argv[1]);
	//ft_printf("%s\n", cub_file.assets.north_texture_path);
	check_map(&cub_file.map);
	map_print(&cub_file.map);
	free(cub_file.assets.ceiling_color);
	free(cub_file.assets.floor_color);
	free(cub_file.assets.north_texture_path);
	free(cub_file.assets.south_texture_path);
	free(cub_file.assets.west_texture_path);
	free(cub_file.assets.east_texture_path);
	map_destroy(&cub_file.map);
	return (0);
}
