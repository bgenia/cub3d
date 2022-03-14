/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_direction_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:01:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 17:03:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d/vecmath.h>

#include <libft/tuples.h>

t_double2
	vec_direction_to(t_double2 a, t_double2 b)
{
	b.x -= a.x;
	b.y -= a.y;
	return (vec_normalize(b));
}
