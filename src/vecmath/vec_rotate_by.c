/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate_by.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:27:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 12:42:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/vecmath.h>

t_double2
	vec_rotate_by(t_double2 vec, t_double2 direction)
{
	t_double2	vec_direction;
	double		cos_phi;
	double		sin_phi;

	vec_direction = vec_normalize(vec);
	cos_phi = vec_dot(vec_direction, direction);
	sin_phi = vec_cross(vec_direction, direction);
	return (ft_double2(
			vec.x * cos_phi - vec.y * sin_phi,
			vec.x * sin_phi + vec.y * cos_phi
		));
}
