/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:04:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 14:56:46 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <cub3d/game/game.h>
# include <cub3d/graphics/window.h>
# include <cub3d/render/renderer.h>

typedef struct s_display
{
	void			*mlx;
	t_window		window;
	t_renderer		renderer;
	t_image			minimap;
	t_image			minimap_mask;
}	t_display;

void
display_init(t_display *display, t_game_settings settings);
void
display_destroy(t_display *display);

#endif
