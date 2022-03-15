/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:17:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 16:44:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdbool.h>

# include <cub3d/render/image.h>
# include <cub3d/render/window.h>

typedef struct s_renderer
{
	void		*mlx;
	t_window	*window;
	bool		sync;
	t_image		*current_frame;
	t_image		*next_frame;
	t_image		frames[2];
}	t_renderer;

t_renderer
renderer_create(t_window *window, bool sync);
void
renderer_destroy(t_renderer *renderer);

t_image
renderer_create_frame(t_renderer *renderer);

void
renderer_render_next_frame(t_renderer *renderer);

#endif
