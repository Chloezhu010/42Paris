#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// loop through s1 and s2
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j]) // if char in s1 matches char in s2, move forward s1
			i++;
		j++; // if nothing matches, only move forward s2
	}
	if (s1[i] == '\0') // if i reaches the end, then s1 & s2 match
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[1], av[2]) == 1)
			ft_putstr(av[1]);
		else
			ft_putchar('\n');
	}
	else
		write(1, "\n", 1);
}
