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

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_alphalow(str[i]) == 1)
			count = str[i] - 'a' + 1;
		else if (is_alphaup(str[i]) == 1)
			count = str[i] - 'A' + 1;
		else
			count = 1;
		while (count > 0)
		{
			write(1, &str[i], 1);
			count--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);	
}
