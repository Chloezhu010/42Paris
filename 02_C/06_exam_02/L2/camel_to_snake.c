#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	camel_tosnake(char *str)
{
	int	i;

	i = 0;	
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			ft_putchar('_');
			ft_putchar(str[i] + 32);	
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
		camel_tosnake(av[1]);
	ft_putchar('\n');
}*/
