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

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

void	str_capitalize(char *str)
{
	int	i;

	// handle first char
	if (is_alpha(str[0]) && str[0] >= 'a' && str[0] <= 'z')
		ft_putchar(str[0] - 32);
	else
		ft_putchar(str[0]);
	// loop through the rest of the str
	i = 1;
	while (str[i])
	{
		if (is_alpha(str[i]) && is_space(str[i - 1]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				ft_putchar(str[i] - 32);
			else
				ft_putchar(str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			str_capitalize(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
}
