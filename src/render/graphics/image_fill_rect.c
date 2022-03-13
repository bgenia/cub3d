/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 05:15:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>
#include <libft/math.h>

void
	image_fill_rect(t_image *image, t_color color, t_int2 start, t_int2 end)
{
	int	i;
	int	j;

	i = start.y;
	while (i != end.y)
	{
		j = start.x;
		while (j != end.x)
		{
			image_fill_pixel(image, color, ft_int2(j, i));
			j += ft_sign(end.x - start.x);
		}
		i += ft_sign(end.y - start.y);
	}
}
