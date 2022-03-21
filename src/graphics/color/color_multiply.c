/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:31:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 14:04:07 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/graphics/color.h>

#include <libft/math.h>

t_color
	color_multiply(t_color color, double r, double g, double b)
{
	t_double4	_color;

	_color = color_decompose_d(color);
	_color.x *= r;
	_color.y *= g;
	_color.z *= b;
	return (color_compose_d(_color));
}

t_color
	color_brighten(t_color color, double n)
{
	return (color_multiply(color, n, n, n));
}
