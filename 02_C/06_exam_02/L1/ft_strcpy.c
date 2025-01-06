char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s[1] = '\0';
	return (s1);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char	s1[20] = "hello";
	char	*s2;

	s2 = "pwd";

	printf("%s: %s\n", strcpy(s1, s2), ft_strcpy(s1, s2));
}*/
