#include <unistd.h>

void	print_hex(int n)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (n > 15)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else
		write(1, &hexbase[n], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	nb;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		print_hex(nb);
	}
	write(1, "\n", 1);
}
