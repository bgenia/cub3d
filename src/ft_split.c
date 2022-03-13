#include <stdlib.h>

static	int	ft_count_letter(const char *s, const int a, char c)
{
	int	count;
	int	l;

	count = 0;
	l = a;
	while (s[l] && s[l] != c)
	{
		l++;
		count++;
	}
	return (count);
}

static	int	ft_count_word(char const *s, char c)
{
	int	count;
	int	i;	

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
		if (!s[i])
			return (1);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int	ft_equal(char *b, const char *s, int a, char c)
{
	int	l;

	l = 0;
	while (s[a] && s[a] != c)
		b[l++] = s[a++];
	b[l] = '\0';
	return (a);
}

static	int	ft_fill_str(char **b, char const *s, char c)
{
	int		a;
	int		i;

	a = 0;
	i = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c)
		{
			b[i] = malloc(sizeof(char) * (ft_count_letter(s, a, c) + 1));
			if (b[i] == 0)
			{
				while (i >= 0)
					free(b[--i]);
				return (0);
			}
			a = ft_equal(b[i++], s, a, c);
			continue ;
		}
		a++;
	}
	b[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**b;

	if (s == NULL)
		return (NULL);
	b = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (b == 0)
		return (NULL);
	if (ft_fill_str(b, s, c) == 0)
	{
		free(b);
		return (NULL);
	}
	return (b);
}
