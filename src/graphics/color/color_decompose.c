/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_decompose.c                                  :+:      :+:    :+:   */
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

t_int4
	color_decompose(t_color color)
{
	return ((t_int4){
		color_get_alpha(color),
		color_get_red(color),
		color_get_green(color),
		color_get_blue(color)
	});
}

t_double4
	color_decompose_d(t_color color)
{
	return ((t_double4){
		(double)color_get_alpha(color) / 255,
		(double)color_get_red(color) / 255,
		(double)color_get_green(color) / 255,
		(double)color_get_blue(color) / 255
	});
}
