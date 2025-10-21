#ifndef BSQ_H
# define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int lines;
    int width;
    char empty;
    char obstacle;
    char full;
    char **map;
} Map;


# endif