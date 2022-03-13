/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:15:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 04:16:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>

#include <mlx.h>

void
	image_destroy(t_image *image)
{
	mlx_destroy_image(image->mlx, image->mlx_image);
}
