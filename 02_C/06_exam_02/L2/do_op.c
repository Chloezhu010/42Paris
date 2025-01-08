#include <stdio.h>
#include <stdlib.h>

int	do_op(char *s1, char c, char *s2)
{
	int	nbr1;
	int	nbr2;
	int	res;	

	nbr1 = atoi(s1);
	nbr2 = atoi(s2);
	res = 0;
	if (c == '*')
		res = nbr1 * nbr2;
	else if (c == '/')
		res = nbr1 / nbr2;
	else if (c == '+')
		res = nbr1 + nbr2;
	else if (c == '-')
		res = nbr1 - nbr2;
	else if (c == '%')
		res = nbr1 % nbr2;
	return (res);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		printf("%d", do_op(av[1], av[2][0], av[3]));	
	printf("\n");
}
