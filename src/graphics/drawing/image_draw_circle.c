/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:26:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 13:26:45 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>
#include <libft/math.h>

static bool
	_is_on_circle(t_int2 center, int radius, t_int2 point)
{
	point.x -= center.x;
	point.x *= point.x;
	point.y -= center.y;
	point.y *= point.y;
	return (ft_absd(sqrt(point.x + point.y) - radius) <= 0.5);
}

void
	image_draw_circle(
		t_image *image,
		t_brush brush,
		t_int2 position,
		int radius
	)
{
	t_int2	i;

	i.x = position.x - radius;
	while (i.x < position.x + radius + 1)
	{
		i.y = position.y - radius;
		while (i.y < position.y + radius + 1)
		{
			if (_is_on_circle(position, radius, i))
				image_draw_brush(image, brush, i);
			i.y++;
		}
		i.x++;
	}
}
