#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

void	rev_wstr(char *str)
{
	int	start;
	int	end;
	int	i;
	int	flag;

	i = 0;
	// find the end of the string
	while (str[i])
		i++;
	// start from the end
	while (i >= 0)
	{
		// skip through the space and null teriminator
		while (str[i] == '\0' || is_space(str[i]) == 1)
			i--;
		// find the end of the word
		end = i;
		// find the beginning of the word
		while (str[i] && is_space(str[i]) == 0)
			i--;
		start = i + 1;
		// store the start index to check if it's the 1st word
		flag = start;
		// print the current word
		while (start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		// if it's not the first word, aka to print as the last word, then add space after the word
		if (flag != 0)
			write(1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		rev_wstr(av[1]);
	write(1, "\n", 1);	
}
