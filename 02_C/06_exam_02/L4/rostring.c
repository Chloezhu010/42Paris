#include <unistd.h>

// function to write a word from start to end
void	write_word(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start++;
	}	
}

int	is_space(char c)
{
	if (c == 32 || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	char	*first_start;
	char	*first_end;

	// skip through space
	while (*str && is_space(*str))
		str++;
	// find the start of the first word
	first_start = str;
	// find the end of the first word
	while (*str && is_space(*str) == 0)
		str++;
	first_end = str;
	// skip space after the 1st word
	while (is_space(*str))
		str++;
	// print the rest of the string
	if (*str)
	{
		while (*str)
		{
			if (is_space(*str))
			{
				while (is_space(*str))
					str++;
				if (*str) // if there is a word after space, print the space
					write(1, " ", 1);
			}
			else // print the non-space char
			{
				write(1, str, 1);
				str++;
			}
		}
		write(1, " ", 1); // print a space before the last word
	}
	// print the 1st at the end
	write_word(first_start, first_end);	
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
}
