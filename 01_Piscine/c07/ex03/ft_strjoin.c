#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;
    int	sep_len;

	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
        i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;
	char	*result;

    if (size == 0)
    {
        result = (char*)malloc(sizeof(char));
        result[0] = '\0';
        return (result);
    }
    total_len = ft_total_len(size, strs, sep);
    result = (char*)malloc(sizeof(char) * (total_len + 1));
    if (!result)
        return (0);
    result[0] = '\0';
    i = -1;
    while (++i < size)
    {
        ft_strcat(result, strs[i]);
        if (i < size - 1)
            ft_strcat(result, sep);
    }
    return (result);
}

#include <stdio.h>

int main()
{
    char *strs[] = {"Hello", "world", "this", "is", "42"};
    char *sep = "**";
    int size = 5;
    char *result = ft_strjoin(size, strs, sep);
    printf("%s\n", result);
    free(result);
    return (0);
}