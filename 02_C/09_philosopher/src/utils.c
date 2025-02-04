#include "../incl/philo.h"

void    exit_with_error(char *message)
{
    printf("%s\n", message);
    exit (1);
}

int	ft_atoi(const char *nptr)
{
	int	negative;
	int	i;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * negative);
}