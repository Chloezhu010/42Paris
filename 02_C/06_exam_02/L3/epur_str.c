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

void	epur_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	// trim the space at the beginning
	while (is_space(str[i]))
		i++;
	// loop through the whole string
	while (str[i])
	{
		if (is_space(str[i]) == 1) // flag if encountering a space
			flag = 1;
		else
		{
			if (flag == 1) // indicate there is space in previous char
				ft_putchar(' '); // only put one space
			flag = 0; // update the flag
			ft_putchar(str[i]); // print the char
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	ft_putchar('\n');
}
