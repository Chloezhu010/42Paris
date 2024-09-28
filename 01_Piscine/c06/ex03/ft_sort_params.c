#include <unistdi.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i] && (s1[i] == s2[i]))
		i++;	
	return (s1[i] - s2[i]);
}

void	ft_sort_str(char)

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
			if (ft_cal_ascii(str[j]) > i	
	}
}
