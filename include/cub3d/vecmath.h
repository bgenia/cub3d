/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:58:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 18:53:51 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECMATH_H
# define VECMATH_H

# include <libft/tuples.h>

double
vec_dot(t_double2 a, t_double2 b);

double
vec_cross(t_double2 a, t_double2 b);

double
vec_length(t_double2 vec);

double
vec_distance(t_double2 a, t_double2 b);

t_double2
vec_add(t_double2 a, t_double2 b);

t_double2
vec_direction(double angle);

t_double2
vec_direction_to(t_double2 a, t_double2 b);

t_double2
vec_normalize(t_double2 vec);

t_double2
vec_rotate(t_double2 vec, double angle);

#endif
