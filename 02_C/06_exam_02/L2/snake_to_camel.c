#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	snake_tocamel(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			ft_putchar(str[i + 1] - 32);
			i = i + 1;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		snake_tocamel(av[1]);
	ft_putchar('\n');
}*/
