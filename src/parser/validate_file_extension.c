/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:11:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:12:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <libft/string/string.h>

bool
	validate_file_extension(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	return (ft_streq(extension, ".cub"));
}