/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:02:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 20:04:59 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/vecmath.h>

#include <libft/tuples.h>

#include <math.h>

t_double2
	vec_rotate(t_double2 vec, double angle)
{
	return (ft_double2(
			vec.x * cos(angle) - vec.y * sin(angle),
			vec.x * sin(angle) + vec.y * cos(angle)
		));
}
