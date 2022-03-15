/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:13:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 22:18:22 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <libft/string/string.h>

const static char *g_map_chars = " 01NSEW";

bool
	validate_map_char(char c)
{
	if (ft_strchr(g_map_chars, c))
		return (true);
	return (false);
}
