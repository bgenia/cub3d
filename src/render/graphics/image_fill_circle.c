/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:26:11 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 06:12:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>

static bool
	_is_in_circle(t_int2 center, int radius, t_int2 point)
{
	point.x -= center.x;
	point.x *= point.x;
	point.y -= center.y;
	point.y *= point.y;
	radius *= radius;
	return (point.x + point.y <= radius);
}

void
	image_fill_circle(
		t_image *image,
		t_color color,
		t_int2 position,
		int radius
	)
{
	t_int2	i;

	i.x = position.x - radius;
	while (i.x < position.x + radius)
	{
		i.y = position.y - radius;
		while (i.y < position.y + radius)
		{
			if (_is_in_circle(position, radius, i))
				image_fill_pixel(image, color, i);
			i.y++;
		}
		i.x++;
	}
}
