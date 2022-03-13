/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:36:25 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 19:39:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <cub3d/render/color.h>

#include <libft/string/string.h>
#include <libft/convert.h>
#include <libft/math.h>

t_color
	color_parse(char *color_string)
{
	char	**components;
	int		r;
	int		g;
	int		b;

	components = ft_smsplit(color_string, ',');
	r = ft_clamp(ft_atoi(components[0], NULL), 0, 255);
	g = ft_clamp(ft_atoi(components[1], NULL), 0, 255);
	b = ft_clamp(ft_atoi(components[2], NULL), 0, 255);
	free(components);
	return (color_rgb(r, g, b));
}
