#include <stdlib.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 11))
		return (1);
	else
		return (0);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	count_word(char *str)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0 && flag == 0) // encounter the first char of the world
		{
			count++;
			flag = 1;
		}
		else if (is_space(str[i]) == 1) // when the char is space
			flag = 0;
		i++;
	}
	return (count);	
}

char	**ft_split(char *str)
{
	int	count;
	int	i;
	int	j;
	int	k;
	char	**res;

	if (!str)
		return (NULL);
	count = count_word(str);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	i = 0; // index for iterating through the input string
	j = 0; // start index of the current word
	k = 0; // index for the res array
	while (str[i])
	{
		while (is_space(str[i]) == 1)
			i++;
		j = i; // start of a word
		while (str[i] && is_space(str[i]) == 0)
			i++; // find the end of a word
		if (i > j)
		{
			res[k] = malloc(sizeof(char) * (i - j + 1));
			ft_strncpy(res[k], &str[j], i - j);
			k++;
		}	
	}
	res[k] = NULL;
	return (res);
}
/*
#include <stdio.h>

int	main()
{
	char	*str = " this	is	school    42	!";

	int	count = 0;
	count = count_word(str);
	printf("word count: %d\n", count);
	
	char	**res = ft_split(str);
	int	i = 0;
	while (i < count)
	{	
		printf("split str: %s\n", res[i]);
		i++;
	}
}*/
