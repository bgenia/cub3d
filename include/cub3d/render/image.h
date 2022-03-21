/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:29:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/20 00:07:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stddef.h>

# include <cub3d/render/color.h>

struct	s_image;

typedef struct s_image
{
	void			*mlx;
	size_t			width;
	size_t			height;
	void			*mlx_image;
	char			*data;
	int				bits_per_pixel;
	int				line_length;
	int				endianness;
	struct s_image	*mask;
}	t_image;

t_image
image_create(void *mlx, size_t width, size_t height);
void
image_destroy(t_image *image);

t_color
*image_get_pixel(t_image *image, size_t x, size_t y);

t_image
image_load_xpm_file(void *mlx, char *path);

void
image_use_mask(t_image *image, t_image *mask);
void
image_clear_mask(t_image *image);

#endif
