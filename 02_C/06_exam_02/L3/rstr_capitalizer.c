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

void	rstr_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		// if next char is space, and the char is alpha, then capitalize it
		if (is_alpha(str[i]) && (is_space(str[i + 1]) || str[i + 1] == '\0'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				ft_putchar(str[i] - 32);
			else
				ft_putchar(str[i]);
		}
		// if the char is capitalized, decapitalize it
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i] + 32);
		// others just print as it is
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
			rstr_capitalize(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
}
