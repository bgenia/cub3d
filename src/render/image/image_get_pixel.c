/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_get_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:17:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 05:13:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>

#include <libft/math.h>

#include <mlx.h>

t_color
	*image_get_pixel(t_image *image, size_t x, size_t y)
{
	size_t	pixel_offset;

	x = ft_clamp(x, 0, image->width);
	y = ft_clamp(y, 0, image->height);
	pixel_offset = y * image->line_length + x * (image->bits_per_pixel / 8);
	return ((t_color *)(image->data + pixel_offset));
}
