/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:10:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 04:15:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>

#include <mlx.h>

t_image
	image_create(void *mlx, int width, int height)
{
	t_image	image;

	image = (t_image){.mlx = mlx, .width = width, .height = height};
	image.mlx_image = mlx_new_image(mlx, width, height);
	image.data = mlx_get_data_addr(
			image.mlx_image,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endianness
			);
	return (image);
}
