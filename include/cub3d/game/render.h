/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:49:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/16 23:54:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <cub3d/game/game.h>
# include <cub3d/render/raycasting.h>

t_image
*pick_texture(t_game_state *state, t_ray *ray);

void
game_render_column(
	t_game_state *state,
	t_ray *ray,
	int ray_index,
	int ray_count
	);

void
game_render_next_frame(t_game_state *state);

#endif
