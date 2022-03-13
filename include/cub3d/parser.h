/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:14:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:17:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

# include <cub3d/map.h>
# include <cub3d/asset_manager.h>

typedef struct s_cub_file
{
	t_assets	assets;
	t_map		map;
}	t_cub_file;

bool
validate_file_extension(char *file);

bool
validate_map_char(char c);

t_cub_file
parse_cub_file(char *path);

#endif
