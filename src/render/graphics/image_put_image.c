/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:12:25 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 00:28:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>
#include <cub3d/render/image.h>
#include <cub3d/render/graphics.h>

#include <libft/tuples.h>

void
	image_put_image(t_image *image, t_image *source, t_int2 position)
{
	size_t	i;
	size_t	j;
	t_color	*pixel;

	i = 0;
	while (i < source->height)
	{
		j = 0;
		while (j < source->width)
		{
			pixel = image_get_pixel(source, j, i);
			if (*pixel != 0)
				image_fill_pixel(image, *pixel,
					ft_int2(position.x + j, position.y + i));
			j++;
		}
		i++;
	}
}
