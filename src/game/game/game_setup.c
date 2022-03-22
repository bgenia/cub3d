/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:55:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 17:39:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/game/game.h>
#include <cub3d/game/hooks.h>
#include <cub3d/level/level.h>

#include <libft/string/string.h>

#include <mlx.h>

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

static void
	_place_player(t_game_state *state)
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
				state->player.position = ft_double2(
						(double)j + .5,
						(double)i + .5
						);
				state->player.direction = _get_player_direction(c);
			}
			j++;
		}
		i++;
	}
}

void
	game_setup(t_game_state *state, t_level *level)
{
	state->map = level->map;
	state->asset_manager = asset_manager_create(state->display.mlx);
	asset_manager_load_assets(&state->asset_manager, level->assets);
	_place_player(state);
	register_hooks(state);
	mlx_mouse_hide(state->display.mlx, state->display.window.mlx_window);
}
