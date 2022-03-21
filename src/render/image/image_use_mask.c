/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_use_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:00:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 00:01:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>

void
	image_use_mask(t_image *image, t_image *mask)
{
	image->mask = mask;
}
