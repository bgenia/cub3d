/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:38:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 06:02:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>
#include <libft/math.h>

void
	image_draw_line(t_image *image, t_brush brush, t_int2 start, t_int2 end)
{
	t_double2	position;
	t_double2	delta;
	t_double2	delta_abs;
	double		step;
	int			i;

	delta = ft_double2(end.x - start.x, end.y - start.y);
	delta_abs = ft_double2(ft_absd(delta.x), ft_absd(delta.y));
	if (delta_abs.x > delta_abs.y)
		step = delta_abs.x;
	else
		step = delta_abs.y;
	delta.x /= step;
	delta.y /= step;
	position = ft_double2(start.x, start.y);
	i = 0;
	while (i < step)
	{
		image_draw_brush(image, brush, ft_int2(position.x, position.y));
		position.x += delta.x;
		position.y += delta.y;
		i++;
	}
}
