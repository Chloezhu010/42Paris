char	*ft_strlowcase(char * str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' &&  str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char test[] = "42BORNTOCOde";
	printf("%s\n", ft_strlowcase(test));
}*/
