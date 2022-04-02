/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_depth_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:45:48 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/24 00:46:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/game/game.h>

#include <libft/vector/vector.h>

void
	clear_depth_data(t_game_state *state)
{
	ft_vector_clear(state->display.vec_depth);
}
