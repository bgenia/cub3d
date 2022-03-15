/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:51:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/15 06:44:39 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <stdbool.h>

# include <libft/tuples.h>

# define RAY_CORRECTION_COEFFICENT 1e-5

typedef enum e_ray_type
{
	RAY_VERTICAL,
	RAY_HORIZONTAL
}	t_ray_type;
typedef struct s_ray
{
	t_ray_type	type;
	t_double2	origin;
	t_double2	direction;
	t_double2	position;
	t_double2	offset;
	double		length;
}	t_ray;

typedef struct s_ray_hit_predicate
{
	bool	(*predicate)(t_double2 position, void *arg);
	void	*arg;
}	t_ray_hit_predicate;

t_ray
ray_create_vertical(t_double2 origin, t_double2 direction);
t_ray
ray_create_horizontal(t_double2 origin, t_double2 direction);

void
ray_cast(
	t_ray *ray,
	int iteration_limit,
	t_ray_hit_predicate predicate
	);

t_ray
cast_ray(
	t_double2 origin,
	t_double2 direction,
	int iteration_limit,
	t_ray_hit_predicate predicate
	);

#endif
