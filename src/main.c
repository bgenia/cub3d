/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/10 11:48:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/io/printf.h>

#include <mlx.h>

int
	handle_exit(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int
	main(void)
{
	void	*mlx;
	void	*window;

	ft_printf("Running cub3d!\n");
	mlx = mlx_init();
	window = mlx_new_window(mlx, 640, 480, "cub3d sample");
	mlx_hook(window, 17, 0, handle_exit, mlx);
	mlx_string_put(mlx, window, 100, 100, 0x00FF00, "Hello world!");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
