#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char x, char y)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == x)
			ft_putchar(y);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	x;
	char	y;

	if (ac == 4)
	{
		if (av[2][1] || av[3][1])
		{
			write(1, "\n", 1);
			exit(1);
		}
		x = av[2][0];
		y = av[3][0];
		search_and_replace(av[1], x, y);
	}
	write(1, "\n", 1);
}
