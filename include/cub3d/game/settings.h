/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:08:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 14:45:47 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdbool.h>
# include <stddef.h>

# include <cub3d/graphics/color.h>

# include <libft/tuples.h>

# ifdef BONUS
#  define BONUS_MINIMAP 1
#  define BONUS_MOUSE_ROTATION 1
# else
#  define BONUS_MINIMAP 0
#  define BONUS_MOUSE_ROTATION 0
# endif

# define MINIMAP_COLOR_FRAME	0x00a32d
# define MINIMAP_COLOR_BG		0x002109
# define MINIMAP_COLOR_WALL		0x00691d
# define MINIMAP_COLOR_PLAYER	0x00b031
# define MINIMAP_COLOR_RAY		0x00b031

# define PERFORMANCE_OVERLAY_COLOR 0x00ff00

typedef struct s_game_settings
{
	size_t	window_width;
	size_t	window_height;
	double	fov;
	int		column_width;
	bool	shading;
	bool	sync;
	bool	performance_overlay;
	double	movement_speed;
	double	rotation_speed;
	double	shift_multiplier;
	bool	mouse_rotation;
	struct s_minimap_settings {
		bool	enabled;
		t_int2	position;
		int		size;
		double	scale;
		int		ray_count;
	}		minimap;
}	t_game_settings;

#endif
