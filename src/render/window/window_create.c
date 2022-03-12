/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:00:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 05:08:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/render/image.h>
#include <cub3d/render/window.h>

#include <mlx.h>

t_window
	window_create(void *mlx, size_t width, size_t height, char *title)
{
	t_window	window;

	window = (t_window){
		.mlx = mlx,
		.width = width,
		.height = height,
		.title = title
	};
	window.mlx_window = mlx_new_window(mlx, width, height, title);
	return (window);
}
