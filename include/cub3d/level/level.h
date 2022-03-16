/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:14:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:25:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include <stdbool.h>

# include <cub3d/level/map.h>
# include <cub3d/level/assets.h>

typedef struct s_level
{
	t_assets	assets;
	t_map		map;
}	t_level;

bool
validate_level_file_extension(char *file);

bool
validate_map_char(char c);

t_level
level_load_from_file(char *path);

void
level_destroy(t_level *file);

#endif
