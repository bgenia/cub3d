/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:30:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/18 22:17:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	**vec_value;
}	t_map;

t_map
map_create(void);
void
map_destroy(t_map *map);

void
map_add_line(t_map *map);
void
map_push_char(t_map *map, char c);
void
map_push_line(t_map *map, char *line);

char
map_get(t_map *map, size_t x, size_t y);

void
map_print(t_map *map);

void
map_validate(t_map *map);

bool
validate_map_char(char c);
bool
validate_map_border(t_map *map, size_t i, size_t j, char c);

#endif
