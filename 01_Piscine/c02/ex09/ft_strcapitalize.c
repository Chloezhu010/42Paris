int	ft_str_is_alpha(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			return (2);
		else return (0);
	}
}

char    *ft_strlowcase(char * str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char    *ft_strupercase(char * str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 47)
		{
			ft_strupercase(str[i+1]);
		}
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char test[] = "salut, comment tu vas? 42mots quarante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(test));
}
