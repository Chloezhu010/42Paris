#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == 32 || c == '\t')
		return (1);
	else
		return (0);
}

void	expand_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (is_space(str[i])) // skip the space at the beginning
		i++;
	while (str[i])
	{
		if (is_space(str[i]))
			flag = 1;
		else
		{
			if (flag == 1)
				write(1, "   ", 3);
			flag = 0;
			ft_putchar(str[i]);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	ft_putchar('\n');
}
