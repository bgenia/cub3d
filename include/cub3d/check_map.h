/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:45:47 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/18 20:53:08 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include <cub3d/map.h>
# include <stdbool.h>
# include <libft/utils.h>
# include <libft/string/string.h>

void
	check_map(t_map *map);
bool
	validate_map_char(char c);
bool
	validate_map_border(t_map *map, size_t i, size_t j, char c);

#endif