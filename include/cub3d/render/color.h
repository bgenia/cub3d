/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:44:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 19:40:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef unsigned char \
	t_color_component;

typedef unsigned int \
	t_color;

t_color
color_argb(
	t_color_component a,
	t_color_component r,
	t_color_component g,
	t_color_component b
	);

t_color
color_rgb(
	t_color_component r,
	t_color_component g,
	t_color_component b
	);

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
color_multiply_components(t_color color, double r, double g, double b);
t_color
color_multiply_all_components(t_color color, double n);

#endif
