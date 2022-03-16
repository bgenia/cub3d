/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:47:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:23:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/level/assets.h>

t_asset_manager
	asset_manager_create(void *mlx)
{
	return ((t_asset_manager){.mlx = mlx});
}
