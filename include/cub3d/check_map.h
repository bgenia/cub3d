/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:45:47 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/15 22:41:02 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include <cub3d/map.h>

void
	check_map(t_map *map);
bool
	validate_map_char(char c);

#endif