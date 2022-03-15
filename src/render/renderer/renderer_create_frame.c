/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_create_frame.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:39:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 16:40:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>
#include <cub3d/render/renderer.h>

t_image
	renderer_create_frame(t_renderer *renderer)
{
	return (image_create(
			renderer->mlx,
			renderer->window->width,
			renderer->window->height
		));
}
