#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printed(char c, int *printed)
{
	if (printed[(unsigned char)c] == 1)
		return (1); // char has been printed
	else
		return (0); // char has not been printed
}

void	inter(char *s1, char *s2)
{
	int	printed[256] = {0}; // array to track the printed char
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && is_printed(s1[i], printed) == 0)
			{
				ft_putchar(s1[i]); // print the char
				printed[(unsigned char)s1[i]] = 1; // mark it as printed
				break; // move the next char in s1
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
}
