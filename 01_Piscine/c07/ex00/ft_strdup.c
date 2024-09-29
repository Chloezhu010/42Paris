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

/*
- malloc allocate size bytes of memory, then return a pointer to the alloc memory
- (cast-type*) malloc(byte-size)
https://www.codequoi.com/en/malloc-allocating-memory-in-c/#:~:text=To%20malloc%20a%20string%20of,char%20for%20the%20final%20%5C0%20.

*/
