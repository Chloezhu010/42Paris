#include <unistd.h>

int	is_alphalow(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	is_alphaup(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_alphalow(str[i]) == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'm')
				ft_putchar(str[i] + 13);
			else
				ft_putchar(str[i] - 13);
		}
		else if (is_alphaup(str[i]) == 1)
		{
			if (str[i] >= 'A' && str[i] <= 'M')
				ft_putchar(str[i] + 13);
			else
				ft_putchar(str[i] - 13);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write(1, "\n", 1);
}
