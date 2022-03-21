/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:17:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 16:43:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/settings.h>
#include <cub3d/game/game.h>
#include <cub3d/graphics/image.h>
#include <cub3d/graphics/drawing.h>
#include <cub3d/render/minimap.h>

#include <libft/tuples.h>

void
	render_minimap_walls(t_game_state *state, t_image *minimap)
{
	t_int2		from;
	t_int2		to;
	t_int2		i;
	t_double2	position;

	image_fill(minimap, MINIMAP_COLOR_BG);
	compute_observable_map(state, &from, &to);
	i.y = from.y;
	while (i.y < to.y)
	{
		i.x = from.x;
		while (i.x < to.x)
		{
			position = ft_double2(i.x - state->player.position.x,
					i.y - state->player.position.y);
			if (map_get(&state->map, i.x, i.y) == '1')
				fill_minimap_wall(state, minimap, position);
			i.x++;
		}
		i.y++;
	}
}
