/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:54:27 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 23:54:44 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/image.h>
#include <cub3d/render/raycasting.h>
#include <cub3d/game/game.h>

t_image
	*pick_texture(t_game_state *state, t_ray *ray)
{
	if (ray->type == RAY_HORIZONTAL)
	{
		if (ray->direction.x > 0)
			return (&state->asset_manager.south_texture);
		else
			return (&state->asset_manager.north_texture);
	}
	else
	{
		if (ray->direction.y > 0)
			return (&state->asset_manager.east_texture);
		else
			return (&state->asset_manager.west_texture);
	}
}
