/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:55:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 21:02:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>
#include <cub3d/parser.h>

#include <libft/string/string.h>

static bool
	_is_player_char(char c)
{
	return (!!ft_strchr("NSWE", c));
}

static t_double2
	_get_player_direction(char c)
{
	t_double2	direction;

	direction = ft_double2(0, 0);
	if (c == 'N')
		direction.y = -1;
	if (c == 'S')
		direction.y = 1;
	if (c == 'W')
		direction.x = -1;
	if (c == 'E')
		direction.x = 1;
	return (direction);
}

// FIXME: Cringe formatting at 62,63
static void
	_find_player(t_game_state *state)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < state->map.height)
	{
		j = 0;
		while (j < state->map.width)
		{
			c = map_get(&state->map, j, i);
			if (_is_player_char(c))
			{
				state->player.position = \
					ft_double2((double)j + .5, (double)i + .5);
				state->player.direction = _get_player_direction(c);
			}
			j++;
		}
		i++;
	}
}

void
	game_setup(t_game_state *state, t_cub_file *cub_file)
{
	state->map = cub_file->map;
	state->asset_manager = asset_manager_create(state->display.mlx);
	asset_manager_load_assets(&state->asset_manager, cub_file->assets);
	_find_player(state);
	register_hooks(state);
}
