int	fr_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int main(void){
	printf("%d\n", fr_strlen("hello world"));
}*/
