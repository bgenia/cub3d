/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load_xpm_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:51:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 19:24:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>

#include <mlx.h>

#include <libft/string/string.h>
#include <libft/io/printf.h>

t_image
	image_load_xpm_file(void *mlx, char *path)
{
	t_image	image;
	int		width;
	int		height;

	image.mlx = mlx;
	image.mlx_image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image.mlx_image)
	{
		ft_dprintf(STDERR_FILENO, "cub3d: fatal: "
			"unable to load image from '%s'\n", path);
		exit(1);
	}
	image.width = width;
	image.height = height;
	image.data = mlx_get_data_addr(image.mlx_image, &image.bits_per_pixel,
			&image.line_length, &image.endianness);
	return (image);
}
