/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_free_assets.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:48:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:23:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/assets.h>
#include <cub3d/graphics/image.h>

void
	asset_manager_free_assets(t_asset_manager *asset_manager)
{
	image_destroy(&asset_manager->north_texture);
	image_destroy(&asset_manager->south_texture);
	image_destroy(&asset_manager->west_texture);
	image_destroy(&asset_manager->east_texture);
}
