/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:17:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 17:58:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdbool.h>

# include <cub3d/graphics/image.h>
# include <cub3d/graphics/window.h>

typedef struct s_renderer
{
	void		*mlx;
	t_window	*window;
	bool		sync;
	t_image		*current_frame;
	t_image		*next_frame;
	t_image		frames[2];
}	t_renderer;

void
renderer_init(t_renderer *renderer, t_window *window, bool sync);
void
renderer_destroy(t_renderer *renderer);

t_image
renderer_create_frame(t_renderer *renderer);

void
renderer_render_next_frame(t_renderer *renderer);

#endif
