/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 11:50:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <cub3d/game/game.h>

#include <mlx.h>

#include <libft/io/printf.h>

int
	handle_exit(t_game_state *state)
{
	(void)state;
	exit(EXIT_SUCCESS);
	return (0);
}
