/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:00:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/18 23:35:48 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <cub3d/graphics/image.h>
#include <cub3d/graphics/window.h>

#include <libft/utils.h>

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
	if (!window.mlx_window)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE,
			"Error\nUnable to create mlx window\n");
	return (window);
}
