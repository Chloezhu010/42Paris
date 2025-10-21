#include "bsq.h"

void free_map(Map *map) {
    for (int i = 0; i < map->lines; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

int ft_isprint(char c){
    return (c >= 32 && c <= 126);
}

void print_map(char **map)
{
    int i = -1;
    while (map[++i])
        fprintf(stdout, "%s\n", map[i]);
}

// Reads the map from a file or stdin and returns a Map struct
Map *get_map(char *av) {
    Map *map = malloc(sizeof(Map));
    char *line;
    size_t buf_size = 0;
    int len = 0;

    // open file or stdin
    FILE *file = av? fopen(av, "r"): stdin;
    if (!file)
        return (free(map), NULL);
    // parse 1st line, store info in map struct
    if (fscanf(file, "%d %c %c %c\n", &map->lines, &map->empty, &map->obstacle, &map->full) != 4)
        return (fclose(file), free(map), NULL);

    // allocate space for map rows (line + 1 for NULL termination)
    map->map = calloc(map->lines + 1, sizeof(char *));
    if (!map->map)
        return (fclose(file), free(map), NULL);

    // read each line of the map
    for (int i = 0; i < map->lines; i++) {
        line = NULL;
        len = getline(&line, &buf_size, file);
        // check if line was read successfully and ends with \name
        if (len < 0 || line[len - 1] != '\n')
            return (fclose(file), free(line), free_map(map), NULL);
        // remove the newline character
        line[len - 1] = 0;
        // store width from 1st line
        if (i == 0)
            map->width = ft_strlen(line);
        // verify all lines have same width
        else if (map->width != ft_strlen(line))
            return (fclose(file), free(line), free_map(map), NULL);
        // store line in map struct
        map->map[i] = line;
    }

    // null terminate map array
    map->map[map->lines] = NULL;
    return (fclose(file), map);
}

bool validate_map(Map *map) {
    // validate map exists
    if (!map)
        return false;
    // dimensions are valid (a least 1x1)
    if (map->lines < 1 || map->width < 1)
        return (free_map(map), false);
    // char are distinct (no overlap between empty, obstacle, full)
    if (map->empty == map->full || map->full == map->obstacle || map->empty == map->obstacle)
        return (free_map(map), false);
    // char are printable
    if (!ft_isprint(map->empty) || !ft_isprint(map->full) || !ft_isprint(map->obstacle))
        return (free_map(map), false);
    // map only contain empty or obstacle chars
    for (int i = 0; i < map->lines; i++){
        for (int j = 0; j < map->width; j++) {
            if (map->map[i][j] != map->empty && map->map[i][j] != map->obstacle)
                return (free_map(map), false);
        }
    }
    return (true);
}

int min3(int a, int b, int c) {
    if (a < b && a < c)
        return (a);
    if (b < a && b < c)
        return (b);
    return (c);
}

Map *bsq_resolver(Map *map) {
    // create and allocate dp matrix
    int **dp = calloc(map->lines, sizeof(int *));
    int max_size = 0;
    int best_i = 0;
    int best_j = 0;

    // build dp matrix and find max
    for (int i = 0; i < map->lines; i++) {
        dp[i] = calloc(map->width, sizeof(int));
        for (int j = 0; j < map->width; j++)
        {
            // if obstacle, no square possible
            if (map->map[i][j] == map->obstacle)
                dp[i][j] = 0;
            // first row or column
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            // apply recurrence relation
            else
                dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            // track max_size
            // not >= here, only top-most, left-most qualifies
            if (dp[i][j] > max_size) {
                max_size = dp[i][j];
                best_i = i;
                best_j = j;
            }
        }
    }
    // mark the square on the original map
    // top left corner: best_i - max_size + 1, best_j - max_size + 1
    // bottom right corner: best_i, best_j
    for (int i = best_i - max_size + 1; i <= best_i; i++)
    {
        for (int j = best_j - max_size + 1; j <= best_j; j++)
            map->map[i][j] = map->full;
    }
    // free dp matrix
    for (int i = 0; i < map->lines; i++)
        free(dp[i]);
    free(dp);

    return (map);
}

int bsq(char *av) {
    Map *map = get_map(av);
    if (!validate_map(map))
        return (fprintf(stderr, "map error\n"));
    map = bsq_resolver(map);
    print_map(map->map);
    free_map(map);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1)
        bsq(NULL);
    else {
        for (int i = 1; i < ac; i++)
            bsq(av[i]);
    }
    return (0);
}