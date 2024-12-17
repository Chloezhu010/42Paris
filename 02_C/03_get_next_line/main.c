#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s\n", line);
        free(line);
    }
    return (0);
}