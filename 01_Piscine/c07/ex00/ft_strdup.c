#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	len;
	char	*str;

	len = ft_strlen(src);
	str = (str*)malloc(len + 1) * 8;
	
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src = "42borntocode";
	char* target = strdup(src);
	char* target2 = ft_strdup(src);
	
	printf("%s; %s\n", target, target2);	
}

