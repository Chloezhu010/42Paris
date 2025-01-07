#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 11))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	last_word(char *str)
{
	int	end;
	int	start;

	// start from the str end, and trim the space, to find the last word's end
	end = 0;
	while (str[end])
		end++;
	while (end > 0 && is_space(str[end - 1]) == 1) // skip the space
		end--;
	// find the last word's start
	start = end;
	while (start > 0 && is_space(str[start - 1]) == 0) // while previous char isn't the space
		start--;
	// print the last word
	if (start < end)
	{
		while (start < end)
			ft_putchar(str[start++]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
}
