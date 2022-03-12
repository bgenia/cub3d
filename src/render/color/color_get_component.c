/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:09:07 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 04:09:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>

t_color_component
	color_get_alpha(t_color color)
{
	return ((color & (0xFF << 24)) >> 24);
}

t_color_component
	color_get_red(t_color color)
{
	return ((color & (0xFF << 16)) >> 16);
}

t_color_component
	color_get_green(t_color color)
{
	return ((color & (0xFF << 8)) >> 8);
}

t_color_component
	color_get_blue(t_color color)
{
	return ((color & (0xFF << 0)) >> 0);
}
