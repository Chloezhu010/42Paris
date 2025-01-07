int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] - s2[i] == 0)
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", strcmp(av[1], av[2]));
		printf("%d\n", ft_strcmp(av[1], av[2]));
	}
	else
		printf("Need input\n");
}*/
