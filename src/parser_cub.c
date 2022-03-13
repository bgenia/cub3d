/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 00:09:15 by bgenia           ###   ########.fr       */
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
# include <stdbool.h>

# include <libft/string/string.h>
# include <libft/io/printf.h>
# include <libft/memory/memory.h>


/*
* Errors
*/
#define DIR			"Directory, not a file"
#define ARGS		"Where is a map?"
#define EXTENSION	"Wrong extension (must be .cub)"
#define FILE_ER		"Cannot open a file"
#define MEM			"No memory"
#define ER_NO		"At least there is no NO"
#define ER_SO		"At least there is no SO"
#define ER_WE		"At least there is no WE"
#define ER_EA		"At least there is no EA"
#define ER_F		"At least there is no F"
#define ER_C		"At least there is no C"
#define MAP_CONTENT	"You can only use 0, 1, N, S, E, W in map"


/*
* HERO and ORIENTATION in the char **map
*/
enum e_hero
{
	N = 2,
	S,
	E,
	W,
	SPACE
};

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_colour;
	char	*ceilling_colour;
	int		**map;
	int		height;
	int		width;
}	t_map;

//LIBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


/*   UTILS
#######################
#######################
*/


t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = ft_malloc(sizeof(t_list));
	if (ptr == 0)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_copy;

	lst_copy = *lst;
	if (lst_copy == NULL)
	{
		*lst = new;
		return ;
	}
	while (lst_copy)
	{
		if (lst_copy->next == NULL)
		{
			lst_copy->next = new;
			return ;
		}
		lst_copy = lst_copy->next;
	}
}


int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		l++;
		lst = lst->next;
	}
	return (l);
}

/* MAIN PART
#######################
#######################
*/

void	ft_exit(char *message)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

bool
	check_extension(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, ".cub") == 0)
		return (true);
	return (false);
}

int	new_get_next_line(char **line, int fd)
{
	char	c;
	int		ret;
	char	*tmp;
	int		i;

	*line = ft_malloc(sizeof(char) * 2);
	*line[0] = '\0';
	while ((ret = read(fd, &c, 1)) != 0)
    {
        if (c == '\n')
            return (1);
        else
        {
            tmp = *line;
            *line = ft_malloc(sizeof(char) * (ft_strlen(*line) + 2));
            i = -1;
            while(tmp[++i])
                line[0][i] = tmp[i];
            line[0][i] = c;
            line[0][i + 1] = '\0';
            free(tmp);
        }
    }
    return (0);
}

char	*check_fill_data(t_map *map)
{
	if (map->no_texture == NULL)
		return (ER_NO);
	if (map->so_texture == NULL)
		return (ER_SO);
	if (map->we_texture == NULL)
		return (ER_WE);
	if (map->ea_texture == NULL)
		return (ER_EA);
	if (map->ceilling_colour == NULL)
		return (ER_C);
	if (map->floor_colour == NULL)
		return (ER_F);
	return (NULL);
}

void	get_data(t_map *map, char *line)
{
	char	**b;

	b = ft_smsplit(line, ' ');
	if (ft_strcmp(b[0], "NO") == 0)
		map->no_texture = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "SO") == 0)
		map->so_texture = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "WE") == 0)
		map->we_texture = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "EA") == 0)
		map->ea_texture = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "F") == 0)
		map->floor_colour = ft_strdup(b[1]);
	else if (ft_strcmp(b[0], "C") == 0)
		map->ceilling_colour = ft_strdup(b[1]);
	free(b);
}

void	get_map_to_list(t_list **temp, char *line)
{
	t_list *new;

	new = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(temp, new);
}

const static char *g_map_chars = " 01NSEW";

bool
	is_valid_map_char(char c)
{
	if (ft_strchr(g_map_chars, c))
		return (true);
	return (false);
}

int	convert_to_map(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'E')
		return (E);
	else if (c == 'W')
		return (W);
	else if (c == ' ')
		return (SPACE);
	ft_exit(MAP_CONTENT);
	return (1);
}


/* Обрезал пробелы, а зачем?
void parse_list_to_map(t_map *map, t_list *temp)
{
	int		i; //для итерации по строкам сплита
	int		q;
	int		a; //для итерации по строке сплита
	int		s; //кол-во символов в интовой строке
	char	**b;
	int		cnt_letters; //кол-во символов в одной строке

	q = ft_lstsize(temp);
	map->map = ft_malloc(sizeof(char *) * (q + 1));
	if (!map->map)
		exit(EXIT_FAILURE);
	while (q > 0)
	{
		b = ft_split(temp->content, ' ');
		i = 0;
		cnt_letters = 0;
		while (b[i])
		{
			cnt_letters++;
			i++;
		}
		map->map[ft_lstsize(temp) - q] = ft_malloc(sizeof(int) * cnt_letters);
		if (!map->map[ft_lstsize(temp) - q])
			exit(EXIT_FAILURE);
		i = 0;
		s = 0;
		while (b[i])
		{
			a = 0;
			while (b[i][a])
			{
				map->map[ft_lstsize(temp) - q][a] = convert_to_map(b[i][a]);
				a++;
				s++;
			}
			i++;
		}

		q--;
	}

}
*/


void parse_list_to_map(t_map *map, t_list *temp)
{
	int		i;
	size_t	max_len;
	int		a;
	char	*s;

	map->map = ft_malloc(sizeof(char *) * (ft_lstsize(temp) + 1));
	a = 0;
	max_len = 0;
	while (temp)
	{
		s = (char *) temp->content;
		i = 0;
		if (ft_strlen(s) > max_len)
			max_len = ft_strlen(s);
		map->map[a] = ft_malloc(sizeof(int) * ft_strlen(s));
		if (!map->map[a])
			exit(EXIT_FAILURE);
		while (s[i])
		{
			map->map[a][i] = convert_to_map(s[i]);
			i++;
		}
		a++;
		temp = temp->next;
	}
	map->height = a;
	map->width = (int) max_len;
}

void	init_map(t_map *map, int fd)
{
	char	*line;
	int		i;
	t_list	*temp;

	i = 1;
	temp = NULL;
	while (i != 0)
	{
		i = new_get_next_line(&line, fd);
		if (!line)
			break ;
		if (line[0] != '\0' && check_fill_data(map))
			get_data(map, line);
		else if (line[0] != '\0')
			get_map_to_list(&temp, line);
		free(line);
	}
	if (i == 0 && check_fill_data(map))
		ft_exit(check_fill_data(map));
	parse_list_to_map(map, temp);
	return ;
}

void	map_to_null(t_map *map)
{
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->floor_colour = NULL;
	map->ceilling_colour = NULL;
}

void	parse_and_draw(char *argv)
{
	int		fd;
	t_map	*map;

	if (check_extension(argv) == -1)
		ft_exit(EXTENSION);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit(FILE_ER);
	map = ft_malloc(sizeof(t_map));
	if (!map)
		ft_exit(MEM);
	map_to_null(map);
	init_map(map, fd);

	//    TEST
	printf("map->no_texture=|%s|\n", map->no_texture);
	printf("map->so_texture=|%s|\n", map->so_texture);
	printf("map->we_texture=|%s|\n", map->we_texture);
	printf("map->ea_texture=|%s|\n", map->ea_texture);
	printf("floor_colour=|%s|\n", map->floor_colour);
	printf("ceilling_colour=|%s|\n", map->ceilling_colour);
	printf("\nTHIS IS MAP\n");
	for (int i = 0; i < map->height; i++)
	{
		int q;
		int s;
		q = 3; //sizeof(map->map[i]) / sizeof(int);
		s = 0;
		while (q--)
			printf("%d", map->map[i][s++]);
		printf("\n");
	}

	free(map->no_texture);
	free(map->we_texture);
	free(map->ea_texture);
	free(map->so_texture);
	free(map->ceilling_colour);
	free(map->floor_colour);
	free(map);

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
