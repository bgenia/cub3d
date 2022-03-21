/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:08:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 19:48:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdbool.h>
# include <stddef.h>

# include <cub3d/graphics/color.h>

# include <libft/tuples.h>

# define MINIMAP_COLOR_FRAME	0x00a32d
# define MINIMAP_COLOR_BG		0x002109
# define MINIMAP_COLOR_WALL		0x00691d
# define MINIMAP_COLOR_PLAYER	0x00b031
# define MINIMAP_COLOR_RAY		0x00b031

typedef struct s_game_settings
{
	size_t	window_width;
	size_t	window_height;
	double	fov;
	int		column_width;
	bool	sync;
	double	movement_speed;
	double	rotation_speed;
	double	shift_multiplier;
	struct s_minimap_settings {
		t_int2	position;
		int		size;
		double	scale;
		int		ray_count;
	}		minimap;
}	t_game_settings;

#endif
