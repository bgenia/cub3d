/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:59:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 13:56:16 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <cub3d/game/game.h>
# include <cub3d/graphics/image.h>
# include <cub3d/raycasting/ray.h>

t_image
*pick_texture(t_game_state *state, t_ray *ray);

void
render_column(t_game_state *state, t_ray *ray, int ray_index, int ray_count);

void
render_scene(t_game_state *state);

#endif
