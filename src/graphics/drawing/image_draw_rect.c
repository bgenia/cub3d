/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>

#include <ft/tuples.h>
#include <ft/math.h>

void
	image_draw_rect(t_image *image, t_brush brush, t_int2 start, t_int2 end)
{
	t_int2	top_right;
	t_int2	bottom_left;

	top_right = ft_int2(end.x, start.y);
	bottom_left = ft_int2(start.x, end.y);
	image_draw_line(image, brush, start, top_right);
	image_draw_line(image, brush, top_right, end);
	image_draw_line(image, brush, end, bottom_left);
	image_draw_line(image, brush, bottom_left, start);
}
