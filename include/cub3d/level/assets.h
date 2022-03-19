/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:54:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/19 19:26:35 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include <stdbool.h>

# include <cub3d/render/color.h>
# include <cub3d/render/image.h>

typedef struct s_assets
{
	char	*floor_color;
	char	*ceiling_color;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
}	t_assets;

typedef struct s_asset_manager
{
	void		*mlx;
	t_assets	*assets;
	t_color		floor_color;
	t_color		ceiling_color;
	t_image		north_texture;
	t_image		south_texture;
	t_image		west_texture;
	t_image		east_texture;
}	t_asset_manager;

t_asset_manager
asset_manager_create(void *mlx);

void
asset_manager_load_assets(t_asset_manager *asset_manager, t_assets assets);

void
asset_manager_free_assets(t_asset_manager *asset_manager);

#endif
