/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:47:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/28 17:01:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include <cub3d/graphics/color.h>
# include <cub3d/graphics/image.h>

# include <ft/tuples.h>

typedef enum e_brush_type
{
	BRUSH_SQUARE,
	BRUSH_CIRCLE
}	t_brush_type;

void
image_fill_pixel(t_image *image, t_color color, t_int2 position);
void
image_fill(t_image *image, t_color color);
void
image_fill_rect(t_image *image, t_color color, t_int2 start, t_int2 end);
void
image_fill_circle(t_image *image, t_color color, t_int2 position, int radius);

typedef struct s_brush
{
	t_color			color;
	t_brush_type	type;
	int				thickness;
}	t_brush;

t_brush
brush_square(t_color color, int thickness);
t_brush
brush_circle(t_color color, int thickness);

void
image_draw_brush(t_image *image, t_brush brush, t_int2 position);
void
image_draw_line(t_image *image, t_brush brush, t_int2 start, t_int2 end);
void
image_draw_rect(t_image *image, t_brush brush, t_int2 start, t_int2 end);
void
image_draw_circle(t_image *image, t_brush brush, t_int2 position, int radius);

void
image_put_image(t_image *image, t_image *source, t_int2 position);

#endif
