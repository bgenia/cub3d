/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:53:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 18:05:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/vecmath.h>

#include <libft/tuples.h>

double
	vec_distance(t_double2 a, t_double2 b)
{
	return (vec_length(ft_double2(a.x - b.x, a.y - b.y)));
}
