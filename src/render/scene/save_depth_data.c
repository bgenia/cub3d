/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_depth_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:43:27 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/24 00:45:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <libft/tuples.h>
#include <libft/vector/vector.h>

void
	save_depth_data(t_game_state *state, int width, double depth)
{
	int	i;

	i = 0;
	while (i < width)
	{
		*(double *)ft_vector_push_back(&state->display.vec_depth) = depth;
		i++;
	}
}
