/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:26:59 by czhu              #+#    #+#             */
/*   Updated: 2024/12/16 16:10:51 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* strjoin, then free the malloc for 1st string 
	return a new str, which is s1+s2 */
char	*ft_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

/* read from the file into the buffer in BUFFER_SIZE and append data to *res string
	stop when encounter '\n' or EOF
	return the updated buffer with data read from the file */
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// if res is NULL, allocate for the terminator byte
	if (!res)
		res = ft_calloc(1, 1);
	// calloc for the chunk size with terminator
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// initialize byte_read for the loop
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// terminate properly
		buffer[byte_read] = '\0';
		// join and free the calloc for res
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (res);
}

/* extract a single line from the buffer
	stop at the newline char
	return the extracted line */
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	// count # of char
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// calloc for i + \n + terminator
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// loop to copy buffer to the line
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if end of line is \0 or \n, replace eol with \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/* after extracting the line, update the buffer by removing the extracted content
	keep the remaining content for future extracting
	return the updated buffer, or NULL if nothing remains */
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find the len of the 1st line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if end of line = \0 then return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// calloc for the next line: strlen(buffer) - 1st line len + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
