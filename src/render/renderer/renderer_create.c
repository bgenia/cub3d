/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:30:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 05:15:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/render/image.h>
#include <cub3d/render/window.h>
#include <cub3d/render/renderer.h>

t_renderer
	renderer_create(t_window *window, bool sync)
{
	t_renderer	renderer;

	renderer = (t_renderer){.mlx = window->mlx, .window = window, .sync = sync};
	renderer.frames[0] = renderer_create_frame(&renderer);
	renderer.frames[1] = renderer_create_frame(&renderer);
	renderer.current_frame = &renderer.frames[0];
	renderer.next_frame = &renderer.frames[1];
	return (renderer);
}
