/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_brush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:58:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 06:15:21 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>

void
	image_draw_brush(t_image *image, t_brush brush, t_int2 position)
{
	if (brush.thickness <= 1)
	{
		image_fill_pixel(image, brush.color, position);
		return ;
	}
	if (brush.type == BRUSH_SQUARE)
	{
		image_fill_rect(image, brush.color,
			ft_int2(position.x - brush.thickness, position.y - brush.thickness),
			ft_int2(position.x + brush.thickness, position.y + brush.thickness)
			);
	}
	if (brush.type == BRUSH_CIRCLE)
	{
		image_fill_circle(image, brush.color, position, brush.thickness);
	}
}
