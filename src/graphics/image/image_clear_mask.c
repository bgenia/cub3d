/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_clear_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:00:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 00:02:16 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <cub3d/graphics/image.h>

void
	image_clear_mask(t_image *image)
{
	image->mask = NULL;
}
