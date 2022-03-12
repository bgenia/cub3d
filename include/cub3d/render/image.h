/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:29:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 04:15:04 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <cub3d/render/color.h>

typedef struct s_image
{
	void	*mlx;
	int		width;
	int		height;
	void	*mlx_image;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}	t_image;

t_image
image_create(void *mlx, int width, int height);
void
image_destroy(t_image *image);

t_color
*image_get_pixel(t_image *image, int x, int y);

#endif
