/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:10:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 05:11:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <cub3d/parser.h>
#include <cub3d/map.h>

void
	cub_file_destroy(t_cub_file *file)
{
	free(file->assets.floor_color);
	free(file->assets.ceiling_color);
	free(file->assets.north_texture_path);
	free(file->assets.south_texture_path);
	free(file->assets.west_texture_path);
	free(file->assets.east_texture_path);
	map_destroy(&file->map);
}
