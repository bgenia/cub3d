/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:30:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 03:13:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>

typedef struct s_map
{
	size_t	witdth;
	size_t	height;
	char	*vec_value;
}	t_map;

t_map
map_create(size_t width, size_t height);
void
map_destroy(t_map *map);

void
map_add_line(t_map *map, char *line);

void
map_print(t_map *map);

char
map_get(t_map *map, size_t x, size_t y);

#endif
