/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:13:03 by bgenia            #+#    #+#             */
<<<<<<< HEAD:src/level/level/validate_map_char.c
/*   Updated: 2022/03/17 00:02:56 by bgenia           ###   ########.fr       */
=======
/*   Updated: 2022/03/18 20:54:57 by drohanne         ###   ########.fr       */
>>>>>>> feature/parser-merge:src/check_map/validate_map_char.c
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/check_map.h>

#include <stdbool.h>

const static char	*g_map_chars = " 01NSEW";

bool
	validate_map_char(char c)
{
	if (ft_strchr(g_map_chars, c))
		return (true);
	return (false);
}
