#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i]) // loop through s1
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j]) // s[i] is in accept, then move to the next char in s
				break;
			j++;
		}
		if (!accept[j]) // if s[i] is not in accept, stop scanning and return i
			return (i);
		i++; // move to the next char in s
	}
	return (i); // if all char in s are in accept, return len of s
}
/*
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%zu\n", strspn(av[1], av[2]));
		printf("%zu\n", ft_strspn(av[1], av[2]));
	}
	else
		printf("need input\n");
}*/
