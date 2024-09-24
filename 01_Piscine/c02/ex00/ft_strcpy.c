char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char src[] = "42borntocodecode code code code code hello hello hello code code code code code code code code code code code code code code code code code code";
	char dest[] = "";

	printf("%s\n", ft_strcpy(dest, src));
}
