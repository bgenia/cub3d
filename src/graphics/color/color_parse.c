/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:36:25 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 14:17:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

#include <cub3d/graphics/color.h>

#include <libft/string/string.h>
#include <libft/convert.h>
#include <libft/math.h>
#include <libft/array.h>
#include <libft/utils.h>
#include <libft/string/string.h>

static bool
	_validate_color_component(intmax_t component)
{
	return (component >= 0 && component <= 255);
}

static t_color_component
	_parse_color_component(char *str)
{
	intmax_t	component;
	size_t		length;

	component = ft_atoi(str, &length);
	if (length != ft_strlen(str) || errno == EINVAL || errno == ERANGE
		|| !_validate_color_component(component))
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nInvalid color\n");
	return ((t_color_component)component);
}

t_color
	color_parse(char *color_string)
{
	char		**components;
	intmax_t	r;
	intmax_t	g;
	intmax_t	b;

	components = ft_smsplit(color_string, ',');
	if (ft_arrlen(components, sizeof(*components)) != 3)
		ft_exitf(STDERR_FILENO, EXIT_FAILURE, "Error\nInvalid color\n");
	r = _parse_color_component(components[0]);
	g = _parse_color_component(components[1]);
	b = _parse_color_component(components[2]);
	free(components);
	return (color_compose((t_int4){0, r, g, b}));
}
