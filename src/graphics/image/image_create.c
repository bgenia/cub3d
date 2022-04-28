/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:10:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>

#include <ft/utils.h>

#include <mlx.h>

t_image
	image_create(void *mlx, size_t width, size_t height)
{
	t_image	image;

	image = (t_image){.mlx = mlx, .width = width, .height = height};
	image.mlx_image = mlx_new_image(mlx, width, height);
	if (!image.mlx_image)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\n"
			"Unable to create mlx image\n");
	image.data = mlx_get_data_addr(
			image.mlx_image,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endianness
			);
	return (image);
}
