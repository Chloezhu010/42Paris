int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main()
{
	char	*str;

	str = "hello world";
	printf("%s, %d\n", str, ft_strlen(str));
}*/
