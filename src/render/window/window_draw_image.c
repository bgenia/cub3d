/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:00:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 05:08:46 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>
#include <cub3d/render/window.h>

#include <libft/tuples.h>

#include <mlx.h>

void
	window_draw_image(t_window *window, t_image *image)
{
	window_draw_image_at(window, image, ft_int2(0, 0));
}

void
	window_draw_image_at(t_window *window, t_image *image, t_int2 position)
{
	mlx_put_image_to_window(
		window->mlx,
		window->mlx_window,
		image->mlx_image,
		position.x,
		position.y
		);
}
