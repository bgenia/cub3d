/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:25:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 13:26:45 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/graphics/color.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>

void
	image_fill(t_image *image, t_color color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			image_fill_pixel(image, color, ft_int2(j, i));
			j++;
		}
		i++;
	}
}
