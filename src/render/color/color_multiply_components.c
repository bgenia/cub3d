/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multiply_components.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:31:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:03:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>

t_color
	color_multiply_components(t_color color, double r, double g, double b)
{
	return (color_rgb(
			color_get_red(color) * r,
			color_get_green(color) * g,
			color_get_blue(color) * b
		));
}

t_color
	color_multiply_all_components(t_color color, double n)
{
	return (color_rgb(
			color_get_red(color) * n,
			color_get_green(color) * n,
			color_get_blue(color) * n
		));
}
