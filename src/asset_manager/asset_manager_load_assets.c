/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_load_assets.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:33:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 19:43:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/asset_manager.h>
#include <cub3d/render/color.h>
#include <cub3d/render/image.h>

void
	asset_manager_load_assets(t_asset_manager *asset_manager, t_assets assets)
{
	asset_manager->ceiling_color = color_parse(assets.ceiling_color);
	asset_manager->floor_color = color_parse(assets.floor_color);
	asset_manager->north_texture = \
		image_load_xpm_file(asset_manager->mlx, assets.north_texture_path);
	asset_manager->south_texture = \
		image_load_xpm_file(asset_manager->mlx, assets.south_texture_path);
	asset_manager->west_texture = \
		image_load_xpm_file(asset_manager->mlx, assets.west_texture_path);
	asset_manager->east_texture = \
		image_load_xpm_file(asset_manager->mlx, assets.east_texture_path);
}
