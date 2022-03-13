/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:02:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/13 20:10:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/vecmath.h>

#include <libft/tuples.h>

#include <math.h>

double
	vec_cross(t_double2 a, t_double2 b)
{
	return (a.x * b.y - a.y * b.x);
}
