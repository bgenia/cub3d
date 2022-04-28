/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:39:39 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <cub3d/game/game.h>

# include <ft/tuples.h>

void
compute_observable_map(t_game_state *state, t_int2 *from, t_int2 *to);

void
fill_minimap_wall(t_game_state *state, t_image *minimap, t_double2 position);

void
render_minimap_walls(t_game_state *state, t_image *minimap);

void
render_minimap_rays(t_game_state *state, t_image *minimap);

void
render_minimap_overlay(t_game_state *state, t_image *minimap);

void
render_minimap(t_game_state *state);

#endif
