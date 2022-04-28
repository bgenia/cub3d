/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_get_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:17:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>

#include <ft/math.h>

#include <mlx.h>

t_color
	*image_get_pixel(t_image *image, size_t x, size_t y)
{
	size_t	pixel_offset;

	x = ft_clamp(x, 0, image->width - 1);
	y = ft_clamp(y, 0, image->height - 1);
	pixel_offset = y * image->line_length + x * (image->bits_per_pixel / 8);
	return ((t_color *)(image->data + pixel_offset));
}
