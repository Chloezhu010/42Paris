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
		ft_putchar(n+ '0');
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while(str[i] && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++; 
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	int	nb;
	int	i;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb > 0 && nb <= 238609294)
		{
			i = 1;
			while (i < 10)
			{
				ft_putchar(i + '0');
				write(1, " x ", 3);
				ft_putnbr(nb);
				write(1, " = ", 3);
				ft_putnbr(i * nb);
				write(1, "\n", 1);
				i++;
			}	
		}
	}
	else
		ft_putchar('\n');
}
