/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brush_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 05:23:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 06:07:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/render/color.h>
#include <cub3d/render/graphics.h>

t_brush
	brush_square(t_color color, int thickness)
{
	return ((t_brush){
		.color = color,
		.type = BRUSH_SQUARE,
		.thickness = thickness
	});
}