/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:02:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/21 13:53:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d/vecmath.h>

#include <libft/tuples.h>

double
	vec_length(t_double2 vec)
{
	return (hypot(vec.x, vec.y));
}
