/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 16:45:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>
#include <cub3d/render/renderer.h>

void
	renderer_destroy(t_renderer *renderer)
{
	image_destroy(&renderer->frames[0]);
	image_destroy(&renderer->frames[0]);
}
