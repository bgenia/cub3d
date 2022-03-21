/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 12:45:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>

void
	image_fill_pixel(t_image *image, t_color color, t_int2 position)
{
	t_color	*mask_pixel;
	t_color	*pixel;

	if (position.x < 0 || position.x >= (int)image->width)
		return ;
	if (position.y < 0 || position.y >= (int)image->height)
		return ;
	if (image->mask)
	{
		mask_pixel = image_get_pixel(image->mask, position.x, position.y);
		if (*mask_pixel == 0)
			return ;
	}
	pixel = image_get_pixel(image, position.x, position.y);
	*pixel = color;
}
