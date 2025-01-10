#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	main(int ac, char **av)
{
	int	i;

	(void)av;
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
			i++;
		ft_putnbr(i - 1);
		ft_putchar('\n');
	}
	else
		write(1, "0\n", 2);
}
