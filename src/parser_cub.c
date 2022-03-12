/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 23:24:08 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




/*   HEADER
#######################
#######################
*/


# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*
* Errors
*/
#define DIR			"Directory, not a file"
#define ARGS		"Where is a map?"
#define EXTENSION	"Wrong extension (must be .cub)"
#define FILE_ER		"Cannot open a file"

/*
* HERO and ORIENTATION in the char **map
*/
enum e_hero
{
	N = 2,
	S,
	E,
	W
};

typedef struct s_map
{
	char	**map;
}	t_map;



/*   UTILS
#######################
#######################
*/




size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/* MAIN PART
#######################
#######################
*/

void	ft_exit(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	check_extension(char *s)
{
	int	q;

	q = ft_strlen(s);
	if (q < 4 || s[q - 1] != 'b' || s[q - 2] != 'u'
		|| s[q - 3] != 'c' || s[q - 4] != '.')
		return (-1);
	return (0);
}

void	parse_and_draw(char *argv)
{
	int		fd;

	if (check_extension(argv) == -1)
		ft_exit(EXTENSION);
	fd = open(argv, O_RDONLY);
	//printf("N=%d, S=%d, E=%d, W=%d\n", N, S, E, W);
	if (fd == -1)
		ft_exit(FILE_ER);

}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], __O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			ft_exit(DIR);
		}
		parse_and_draw(argv[1]);
	}
	else
		ft_exit(ARGS);
	return (0);
}
