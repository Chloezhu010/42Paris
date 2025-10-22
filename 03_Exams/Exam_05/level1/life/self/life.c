#include "life.h"
/*
    create_map: create blank board
    populate_map: draw on board based on the rules
    game_of_life: simulate the game
    print_map: printout the result
*/

void print_map(char **map) {
    int i = -1;
    int j;
    while (map[++i]) {
        j = -1;
        while (map[i][++j])
            putchar(map[i][j]);
        putchar('\n');
    }
}

void free_map(char **map) {
    int i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}

// create a blank board with ' '
char **create_map(int width, int height) {
    char **map = calloc(height + 1, sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = calloc(width + 1, sizeof(char));
        for (int j = 0; j < width; j++)
            map[i][j] = ' ';
    }
    return (map);
}

char **populate_map(char **map, int width, int height) {
    int i = 0;
    int j = 0;
    char buf;
    bool writing = false;

    while (read(0, &buf, 1)) {
        if (buf == 's' && i < height - 1)
            i++;
        else if (buf == 'w' && i > 0)
            i--;
        else if (buf == 'a' && j > 0)
            j--;
        else if (buf == 'd' && j < width - 1)
            j++;
        else if (buf == 'x')
            writing = !writing; // toggle the pen
        // draw if pen is down
        if (writing)
            map[i][j] = '0';
    }
    return (map); // return the map with initial drawing
}

char **game_of_life(char **map, int width, int height) {
    char **new_map = create_map(width, height);
    int count; // track alive neighbors each cell has

    // main loop
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            count = 0;
            
            // for each cell, count its neighbors, apply result, write to new_map
            if (map[i][j] == '0') // cell is alive
            {
                // check 8 neighbors
                if (i > 0 && map[i - 1][j] == '0' )
                    count++;
                if (i > 0 && j > 0 && map[i - 1][j - 1] == '0')
                    count++;
                if (i > 0 && j < width - 1 && map[i - 1][j + 1] == '0')
                    count++;
                if (j > 0 && map[i][j - 1] == '0')
                    count++;
                if (j < width - 1 && map[i][j + 1] == '0')
                    count++;
                if (j > 0 && i < height - 1 && map[i + 1][j - 1] == '0')
                    count++;
                if (i < height - 1 && map[i + 1][j] == '0')
                    count++;
                if (i < height - 1 && j < width - 1 && map[i + 1][j + 1] == '0')
                    count++;

                // apply alive cell rule
                if (count == 2 || count == 3)
                    new_map[i][j] = '0';
            }
            else if (map[i][j] == ' ') // cell is dead
            {
                // check 8 neighbors
                if (i > 0 && map[i - 1][j] == '0' )
                    count++;
                if (i > 0 && j > 0 && map[i - 1][j - 1] == '0')
                    count++;
                if (i > 0 && j < width - 1 && map[i - 1][j + 1] == '0')
                    count++;
                if (j > 0 && map[i][j - 1] == '0')
                    count++;
                if (j < width - 1 && map[i][j + 1] == '0')
                    count++;
                if (j > 0 && i < height - 1 && map[i + 1][j - 1] == '0')
                    count++;
                if (i < height - 1 && map[i + 1][j] == '0')
                    count++;
                if (i < height - 1 && j < width - 1 && map[i + 1][j + 1] == '0')
                    count++;

                // apply dead cell rule
                if (count == 3)
                    new_map[i][j] = '0';
            }
        }
    }


    // cleanup and return the new map
    free_map(map);
    return (new_map);
}


void life(char **av)
{
    // convert input into width, height, iteration
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iter = atoi(av[3]);

    // create map, populate map, iterate through game of life
    char **map = create_map(width, height);
    map = populate_map(map, width, height);
    for (int i = 0; i < iter; i++)
        map = game_of_life(map, width, height);
    
    // printout result, cleanup map
    print_map(map);
    free_map(map);
}

int main(int ac, char **av)
{
    // input eg: ./a.out 3 3 1
    if (ac != 4)
        return (1);
    life(av);
    return (0);
}