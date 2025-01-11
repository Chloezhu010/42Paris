#include <stdlib.h>

int	abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	len(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count = 1;
	nb = abs(nb);
	while (nb >= 1)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int	nb_len;
	int	abs_nb;
	int	i;

	nb_len = len(nbr);
	res = malloc(sizeof(char) * (nb_len + 1)); // need null terimnated
	if (!res)
		return (NULL);
	if (nbr < 0)
		res[0] = '-'; // handle negative case
	else if (nbr == 0)
		res[0] = '0'; // handle zero case
	abs_nb = abs(nbr);
	i = nb_len - 1;
	while (abs_nb > 0)
	{
		res[i] = abs_nb % 10 + '0';
		abs_nb = abs_nb / 10;
		i--;
	}
	res[nb_len] = '\0';
	return (res);
}
/*
#include <stdio.h>

int 	main(int ac, char **av)
{
	int	nb;
	char	*res;

	(void)ac;
	nb = atoi(av[1]);
	res = ft_itoa(nb);
	printf("%s\n", res);
	free(res);
}

// testing len() function
int	main()
{
	printf("len: %d\n", len(100));
	printf("len: %d\n", len(-42));
	printf("len: %d\n", len(42));
}*/
