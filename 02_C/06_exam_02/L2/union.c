#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printed(char c, int *printed)
{
	if (printed[(unsigned char)c] == 1)
		return (1);
	else
		return (0);
}

void	union_str(char *s1, char *s2)
{
	int	printed[256];
	int	i;

	i = 0;
	while (i < 256)
		printed[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (printed[(unsigned char)s1[i]] == 0)
		{
			ft_putchar(s1[i]);
			printed[(unsigned char)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{	
		if (printed[(unsigned char)s2[i]] == 0)
		{
			ft_putchar(s2[i]);
			printed[(unsigned char)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_str(av[1], av[2]);
	write(1, "\n", 1);
}
