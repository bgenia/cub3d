/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load_xpm_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:51:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>

#include <mlx.h>

#include <ft/string/string.h>
#include <ft/utils.h>

t_image
	image_load_xpm_file(void *mlx, char *path)
{
	t_image	image;
	int		width;
	int		height;

	image.mlx = mlx;
	image.mlx_image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image.mlx_image)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\n"
			"Unable to load image from '%s'\n", path);
	image.width = width;
	image.height = height;
	image.data = mlx_get_data_addr(image.mlx_image, &image.bits_per_pixel,
			&image.line_length, &image.endianness);
	return (image);
}
