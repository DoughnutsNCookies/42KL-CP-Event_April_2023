#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	ft_freesplit(char **split)
{
	int	i = -1;

	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}

static int	is_charset(char c, char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		if (str[i] == c)
			return (1);
	return (0);
}

static int	ft_getwc_charset(char const *s, char *str)
{
	size_t	count = 0;
	size_t	i = 0;

	while (s[i] != '\0')
	{
		while (is_charset(s[i], str))
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && is_charset(s[i], str) == 0)
			i++;
		count++;
	}
	return (count);
}

static char	**ft_split_charset(char const *s, char *str)
{
	size_t	i;
	size_t	count;
	char	*wordstart;
	char	**output;

	if (!s)
		return (NULL);
	count = ft_getwc_charset(s, str);
	output = malloc(sizeof(char *) * (count + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (is_charset(*s, str))
			s++;
		if (*s == '\0')
			break ;
		wordstart = (char *)s;
		while (*s != '\0' && is_charset(*s, str) == 0)
			s++;
		output[i++] = strndup(wordstart, s - wordstart);
	}
	output[i] = 0;
	return (output);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	int		max_length = 0;
	char	**split;
	for (int i = 1; av[i] != NULL; i++)
	{
		split = ft_split_charset(av[i], " \n\t\v\f\r");
		for (int j = 0; split[j] != NULL; j++)
			if (strlen(split[j]) > max_length)
				max_length = strlen(split[j]);
		ft_freesplit(split);
	}
	for (int i = 0; i < max_length + 4; i++)
		printf("*");
	printf("\n");
	for (int i = 1; av[i] != NULL; i++)
	{
		split = ft_split_charset(av[i], " \n\t\v\f\r");
		for (int j = 0; split[j] != NULL; j++)
			printf("* %-*s *\n", max_length, split[j]);
		ft_freesplit(split);
	}
	for (int i = 0; i < max_length + 4; i++)
		printf("*");
	printf("\n");
}
