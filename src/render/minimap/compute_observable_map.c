/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_observable_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:57:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/game/game.h>

#include <ft/tuples.h>

void
	compute_observable_map(t_game_state *state, t_int2 *from, t_int2 *to)
{
	double		map_size;
	double		scale;
	t_double2	position;
	t_int2		observable_size;

	map_size = state->settings.minimap.size;
	scale = state->settings.minimap.scale;
	position = state->player.position;
	observable_size = ft_int2(map_size / scale, map_size / scale);
	*from = ft_int2(floor(position.x) - observable_size.x / 2 - 1,
			floor(position.y) - observable_size.y / 2 - 1);
	*to = ft_int2(ceil(position.x) + observable_size.x / 2 + 1,
			ceil(position.y) + observable_size.y / 2 + 1);
}
