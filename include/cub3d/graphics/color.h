/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:44:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 12:47:21 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <libft/tuples.h>

typedef unsigned char \
	t_color_component;

typedef unsigned int \
	t_color;

t_int4
color_decompose(t_color color);

t_color
color_compose(t_int4 color_struct);

t_double4
color_decompose_d(t_color color);
t_color
color_compose_d(t_double4 color);

t_color
color_parse(char *color_string);

t_color_component
color_get_alpha(t_color color);
t_color_component
color_get_red(t_color color);
t_color_component
color_get_green(t_color color);
t_color_component
color_get_blue(t_color color);

t_color
color_multiply(t_color color, double r, double g, double b);
t_color
color_brighten(t_color color, double n);

#endif
