#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	// scan through s1, to find the first occurence of any char in s2
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	// if nothing found, return null
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*res;
	char	*res2;
	
	if (ac == 3)
	{
		res = strpbrk(av[1], av[2]);
		res2 = ft_strpbrk(av[1], av[2]);
		if (res || res2)
		{
			printf("%s\n", res);
			printf("%s\n", res2);
		}
		else
			printf("nothing found\n");
	}
	else
		printf("need input\n");
}*/
