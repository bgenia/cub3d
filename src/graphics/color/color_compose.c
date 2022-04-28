/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_compose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:08:22 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/graphics/color.h>

#include <ft/math.h>
#include <ft/tuples.h>

t_color
	color_compose(t_int4 color)
{
	t_color	result;

	result = 0;
	result += ft_clamp(color.w, 0, 255) << 24;
	result += ft_clamp(color.x, 0, 255) << 16;
	result += ft_clamp(color.y, 0, 255) << 8;
	result += ft_clamp(color.z, 0, 255) << 0;
	return (result);
}

t_color
	color_compose_d(t_double4 color)
{
	t_color	result;

	result = 0;
	result += (t_color_component)(ft_clampd(color.w, 0, 1) * 255) << 24;
	result += (t_color_component)(ft_clampd(color.x, 0, 1) * 255) << 16;
	result += (t_color_component)(ft_clampd(color.y, 0, 1) * 255) << 8;
	result += (t_color_component)(ft_clampd(color.z, 0, 1) * 255) << 0;
	return (result);
}
