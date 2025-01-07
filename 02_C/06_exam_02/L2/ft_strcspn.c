#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!reject[i])
		return (ft_strlen(s));
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%zu\n", strcspn(av[1], av[2]));
		printf("%zu\n", ft_strcspn(av[1], av[2]));
	}
	else
		printf("need input");
}*/
