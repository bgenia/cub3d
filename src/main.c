/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 18:46:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/map/map.h>

int
	main(void)
{
	t_map	map;

	map = map_create();
	map_push_char(&map, '#');
	map_push_char(&map, '#');
	map_push_char(&map, '#');
	map_add_line(&map);
	map_push_char(&map, '#');
	map_push_char(&map, ' ');
	map_push_char(&map, '#');
	map_add_line(&map);
	map_push_char(&map, '#');
	map_push_char(&map, '#');
	map_push_char(&map, '#');
	map_push_line(&map, "...");
	map_print(&map);
	map_destroy(&map);
	return (0);
}
