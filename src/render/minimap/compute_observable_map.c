/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_observable_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:57:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:47:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/game/game.h>

#include <libft/tuples.h>

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
	*from = ft_int2(position.x - observable_size.x / 2,
			position.y - observable_size.y / 2);
	*to = ft_int2(ceil(position.x) + observable_size.x / 2,
			ceil(position.y) + observable_size.y / 2);
}
