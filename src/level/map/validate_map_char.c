/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:13:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/18 22:32:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <cub3d/level/map.h>

#include <libft/string/string.h>

const static char	*g_map_chars = " 01NSEW";

bool
	validate_map_char(char c)
{
	if (ft_strchr(g_map_chars, c))
		return (true);
	return (false);
}
