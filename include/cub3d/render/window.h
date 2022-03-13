/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:57:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 05:07:04 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>

# include <cub3d/render/image.h>

# include <libft/tuples.h>

typedef struct s_window
{
	void	*mlx;
	size_t	width;
	size_t	height;
	char	*title;
	void	*mlx_window;
}	t_window;

t_window
window_create(void *mlx, size_t width, size_t height, char *title);
void
window_destroy(t_window *window);

void
window_draw_image(t_window *window, t_image *image);
void
window_draw_image_at(t_window *window, t_image *image, t_int2 position);

#endif
