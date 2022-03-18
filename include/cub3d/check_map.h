/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:45:47 by drohanne          #+#    #+#             */
/*   Updated: 2022/03/17 22:29:31 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include <cub3d/map.h>

typedef struct s_cycle
{
	size_t	save_i;
	size_t	save_j;
	size_t	i;
	size_t	j;
	int		cycle;
	t_map	*map;
} t_cycle;

void
	check_map(t_map *map);
bool
	validate_map_char(char c);

#endif