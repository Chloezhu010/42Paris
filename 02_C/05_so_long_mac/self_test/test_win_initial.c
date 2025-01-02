#include "minilibx/mlx.h"
#include <stdlib.h>

#define WIDTH           400
#define HEIGHT          500

int main()
{
    void    *mlx_connection;
    void    *mlx_window;

    // initialize the connection
    mlx_connection = mlx_init();
    if (!mlx_connection)
        return (1);
    
    // initialize the window, check if it's valid
    // if not valid, clear up the connection
    mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "Chloe's window");
    if (!mlx_window)
    {
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return (1);
    }

    // event loop: keep the window alive
    mlx_loop(mlx_connection);

    // clean up the memory
    mlx_destroy_window(mlx_connection, mlx_window);
    mlx_destroy_display(mlx_connection);
    free(mlx_connection);
    return (0);
}