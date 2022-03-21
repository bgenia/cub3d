/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_minimap_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:58:48 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:48:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>

#include <libft/tuples.h>

void
	fill_minimap_wall(t_game_state *state, t_image *minimap, t_double2 position)
{
	double		scale;
	int			map_size;
	t_int2		from;
	t_int2		to;

	map_size = state->settings.minimap.size;
	scale = state->settings.minimap.scale;
	from = ft_int2(position.x * scale + map_size / 2,
			position.y * scale + map_size / 2);
	to = ft_int2((position.x + 1) * scale + map_size / 2,
			(position.y + 1) * scale + map_size / 2);
	image_fill_rect(minimap, MINIMAP_COLOR_WALL, from, to);
}
